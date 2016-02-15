#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
} Address;

typedef struct
{
	Address rows[MAX_ROWS];
} Database;

typedef struct
{
	FILE *file;
	Database *database;
} Connection;
 
void die(const char *message)
{
	if(errno)
		perror(message);
	else
		printf("ERROR: %s\n", message);
	
	EXIT_FAILURE;
}

void Address_print(Address *address)
{
	printf("\n%d %s %s\n", 
		address->id, address->name, address->email);
}

void Database_load(Connection *connection)
{
	int run_command = fread(connection->database, 
		sizeof(Database), 1, connection->file);
	if(run_command != 1)
		die("Failed to load database.");

}

Connection *Database_open(const char *filename, char mode)
{
	Connection *connection = malloc(sizeof(Connection));
	if(!connection)
		die("Memory error");

	connection->database = malloc(sizeof(Database));
	if (!connection->database)
		die("Memory error");

	if(mode == 'c')
	{
		connection->file = fopen(filename, "w");
	} 
	else
	{
		connection->file = fopen(filename, "r+");

		if(connection->file)
		{
			Database_load(connection);
		}
	}

	if(!connection->file)
		die("Failed to open the file");

	return connection;
}

void Database_close(Connection *connection)
{
	if(connection->file)
		fclose(connection->file);

	if(connection->database)
		free(connection->database);

	free(connection);
}

void Database_write(Connection *connection)
{
	rewind(connection->file);

	int run_command = fwrite(connection->database, 
		sizeof(Database), 1, connection->file);
	if(run_command != 1) 
		die("Failed to write database.");

	run_command = fflush(connection->file);
	if(run_command == -1) 
		die("Cannot flush database.");
}

void Database_create(Connection *connection)
{
	int index;

	for(index = 0; index < MAX_ROWS; index++)
	{
		Address address = {.id = index, .set = 0};
		connection->database->rows[index] = address;
	}
}

void Database_set(Connection *connection, int id, 
	const char *name, const char *email)
{
	Address *address = &connection->database->rows[id];

	if(address->set)
		die("Already set, delete it first");

	address->set = 1;

	char *temp_name = malloc(sizeof(address->name));
	strncpy(temp_name, name, MAX_DATA);

	temp_name[strlen(temp_name) - 1] = '\0';
	char *rest = strncpy(address->name, temp_name, MAX_DATA);
	if(!rest)
		die("Name copy failed");

	char *temp_email = malloc(sizeof(address->email));
	strncpy(temp_email, email, MAX_DATA);
	
	temp_email[strlen(temp_email) - 1] = '\0';
	rest = strncpy(address->email, temp_email, MAX_DATA);
	if(!rest)
		die("Email copy failed");

	free(temp_name);
	free(temp_email);
}

void Database_get(Connection *connection, int id)
{
	Address *address = &connection->database->rows[id];

	if(address->set)
		Address_print(address);
	else
		die("ID is not set.");
}

void Database_delete(Connection *connection, int id)
{
	Address address = {.id = id, .set = 0};
	connection->database->rows[id] = address;	
}

void Database_list(Connection *connection)
{
	int index;
	Database *database = connection->database;

	for(index = 0; index < MAX_ROWS; index++)
	{
		Address *current_address = &database->rows[index];

		if(current_address->set)
			Address_print(current_address);
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3) 
		die("USAGE: myDB <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	Connection *connection = Database_open(filename, action);
	int id = 0;

	if(argc > 3)
		id = atoi(argv[3]);

	if(id >= MAX_ROWS)
		die("There are not that many records.");

	switch(action)
	{
		case 'c':
			Database_create(connection);
			Database_write(connection);
			break;

		case 'g':
			if(argc != 4)
				die("Need an ID to get record.");

			Database_get(connection, id);
			break;

		case 's':
			if(argc != 6)
				die("Need ID, Name, Email to set record.");

			Database_set(connection, id, argv[4], argv[5]);
			Database_write(connection);
			break;

		case 'd':
			if(argc != 4)
				die("Need ID to delete record.");

			Database_delete(connection, id);
			Database_write(connection);
			break;

		case 'l':
			Database_list(connection);
			break;

		default:
			die("Invalid action, only: c=creat," 
				"g=get, s=set, d=delete, l=list");
	}

	Database_close(connection);

	return(EXIT_SUCCESS);
}

