# 🔐 Versión 1.0.0 - Microservicio de Encriptación SHA-256

Esta es la primera versión estable del microservicio de encriptación desarrollado en C. Permite recibir texto a través de un socket TCP y devolver su hash SHA-256.

## ✅ Características

- Servidor TCP simple y robusto en C.
- Implementación de hashing SHA-256 sin dependencias externas.
- Comunicación por socket con cliente externo (por ejemplo, Python).
- Contenedor Docker para fácil despliegue.

## 🚀 Uso

1. Ejecutar el contenedor o el binario.
2. Enviar texto por socket TCP al puerto 9000.
3. Recibir el hash SHA-256 como respuesta.

## 🧪 Pruebas

Puedes usar `client.py` como cliente de ejemplo para validar su funcionamiento.

---

💡 Ideal para proyectos que necesiten un microservicio ligero, rápido y portátil.
