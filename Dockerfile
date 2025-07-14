# Etapa de compilación
FROM gcc:13 as builder

WORKDIR /app
COPY . .

# Compilar el ejecutable
RUN make

# Etapa final (imagen más ligera)
FROM debian:bookworm-slim

WORKDIR /app
COPY --from=builder /app/encrypt_server .

# Exponer el puerto del microservicio
EXPOSE 9000

# Ejecutar el servidor
CMD ["./encrypt_server"]
