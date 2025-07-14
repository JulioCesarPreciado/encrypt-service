// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "sha256.h"

// Puerto en el que el servidor escuchará
#define PORT 9000
// Tamaño del buffer para recibir datos
#define BUFFER_SIZE 1024

int main() {
    // Variables para el socket del servidor y del cliente
    int server_fd, client_fd;
    // Estructuras para la dirección del servidor y del cliente
    struct sockaddr_in server_addr, client_addr;
    // Buffer para almacenar los datos recibidos y el hash
    char buffer[BUFFER_SIZE] = {0};
    char hash_output[65];

    // Longitud de la dirección del cliente
    socklen_t addr_len = sizeof(client_addr);

    // 1. Crear socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket falló");
        exit(EXIT_FAILURE);
    }

    // 2. Configurar dirección
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 3. Enlazar socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind falló");
        exit(EXIT_FAILURE);
    }

    // 4. Escuchar conexiones
    if (listen(server_fd, 3) < 0) {
        perror("Listen falló");
        exit(EXIT_FAILURE);
    }

    printf("🔐 Servidor escuchando en el puerto %d...\n", PORT);

    // 5. Aceptar y procesar cliente
    while ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len)) >= 0) {
        memset(buffer, 0, BUFFER_SIZE);
        read(client_fd, buffer, BUFFER_SIZE);

        printf("📥 Recibido: %s\n", buffer);

        sha256_string(buffer, hash_output);
        write(client_fd, hash_output, strlen(hash_output));

        printf("📤 Hash enviado: %s\n", hash_output);
        close(client_fd);
    }

    return 0;
}
