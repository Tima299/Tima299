#include <stdio.h>
#include <mysql/mysql.h>

MYSQL *conn;

void connect_to_database() {
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    conn = mysql_real_connect(conn, "localhost", "root", "password", "doctor_management", 0, NULL, 0);
    if (conn == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }

    printf("Connection successful\n");
}

void close_connection() {
    mysql_close(conn);
}

