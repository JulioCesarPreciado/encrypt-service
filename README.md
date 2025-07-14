# 🔐 Microservicio de Encriptación SHA-256 en C

Este proyecto es un microservicio minimalista escrito en C que recibe texto a través de un socket TCP y devuelve su hash SHA-256. Todo se encapsula en un contenedor Docker para facilitar su ejecución.

---

## 🚀 Requisitos

- Docker
- Make (si compilas localmente)

---

## 🛠️ Construcción del ejecutable (opcional)

```bash
make
./encrypt_server
```

---

## 🐳 Construcción del contenedor Docker

```bash
docker build -t encrypt-service .
```

---

## ▶️ Ejecución del contenedor

```bash
docker run -p 9000:9000 encrypt-service
```

Esto expone el microservicio en `localhost:9000`.

---

## 🧪 Pruebas desde Python

Puedes probar el microservicio con este script:

```python
import socket

HOST = '127.0.0.1'
PORT = 9000
mensaje = "Hola desde Python"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(mensaje.encode())
    data = s.recv(1024)

print(f"🔐 Hash recibido: {data.decode()}")
```

---

## 📦 Estructura del proyecto

```
encrypt_service/
├── main.c             # Lógica principal del servidor
├── sha256.c/h         # Implementación del algoritmo SHA-256
├── Makefile           # Compilador del binario
├── Dockerfile         # Imagen de contenedor
└── README.md
```

---

## 🧠 Créditos

SHA-256 basado en implementación de código público de Brad Conte.  
Documentación y contenedor por Julio Preciado.

---

## 📜 Licencia

Este proyecto es de uso libre para fines educativos y de aprendizaje. 🧑‍💻✨
