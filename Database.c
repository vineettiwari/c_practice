#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100
#define SPACE 15

struct Address
{
	int id, set;
	char *name;
	char *email;
};

struct Database
{
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	FILE *file;
	struct Database *db;
};

void Die(const char *message)
{
	if (errno)
		perror(message);
	else
		printf("ERROR: %s\n", message);
	exit(EXIT_FAILURE);
}

void Address_print(struct Address *address)
{
	printf("%*s %*d\n", SPACE, "Id:",	-SPACE, address->id);
	printf("%*s %*s\n", SPACE, "Name:",	-SPACE, address->name);
	printf("%*s %*s\n", SPACE, "Email:",	-SPACE, address->email);
}

void Database_load(struct Connection *connection)
{
	int rc = fread(connection->db, sizeof(struct Database),
						1, connection->file);
	if (rc != 1) Die("Failed to load file.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *connection = malloc(sizeof(struct Connection));
	if (!connection) Die("Memory error");

	connection->db = malloc(sizeof(struct Database));
	if (!connection->db) Die("Merror error");

	if (mode == 'c') {
		connection->file = fopen(filename, "w");
	} else {
		connection->file = fopen(filename, "r+");
		if (connection->file) {
			Database_load(connection);
		}
	}
	if (!connection->file) Die("Failed to open the file");
	return connection;
}

void Database_close(struct Connection *connection)
{
	if (connection) {
		if (connection->file) fclose(connection->file);
		if (connection->db) free(connection->db);
		free(connection);
	}
}

void Database_write(struct Connection *connection)
{
	rewind(connection->file);

	int rc = fwrite(connection->db, sizeof(struct Database),
						1, connection->file);
	if (rc != 1) Die("Failed to write database");

	rc = fflush(connection->file);
	if (rc == -1) Die("Cannot flush database");
}

void Database_create(struct Connection *connection)
{
	for (int i = 0; i < MAX_ROWS; i++) {
		struct Address address = {.id = i, .set = 0};
		connection->db->rows[i] = address;
	}
}

void Database_set(struct Connection *connection, int id,
			const char *name, const char *email)
{

}

int main()
{

	return EXIT_SUCCESS;
}

