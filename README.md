# OS-SysCall

Este repositorio contiene la implementación de system calls en el kernel de Linux para resolver dos problemas específicos: la verificación de expresiones aritméticas y el cálculo del producto punto de vectores. Estos problemas implican el desarrollo de funciones en el kernel que son accesibles desde programas de usuario a través de system calls.

El objetivo principal de este proyecto es brindar una comprensión práctica de cómo agregar funcionalidades al kernel de Linux mediante el desarrollo de system calls y cómo utilizar estas funcionalidades desde programas de usuario. Se explorarán los pasos necesarios para implementar las system calls, compilar el kernel y crear programas de usuario que hagan uso de estas llamadas al sistema.

## Herramientas utilizadas
- VirtualBox 7.0.14
- Ubuntu 16.04.6 Desktop
- [Linux Kernel 4.15.10](https://mirrors.edge.kernel.org/pub/linux/kernel/v4.x/linux-4.15.10.tar.xz)

### Contexto
<details>
  <summary>¿Qué es una Syscall</summary>
  <ol>
     Una syscall, o llamada al sistema, es una interfaz entre un programa de usuario y el sistema operativo. Es utilizada para que los programas de usuario puedan solicitar servicios o recursos del sistema operativo.

Estas llamadas al sistema son esenciales para realizar operaciones que de otra manera serían inaccesibles para un programa de usuario, como el acceso a hardware o la manipulación de archivos en el sistema. Las syscalls permiten a los programas interactuar con el sistema operativo de una manera segura y controlada, asegurando que solo se realicen operaciones permitidas y que se mantenga la estabilidad y seguridad del sistema.
  </ol>
</details>


<details>
  <summary>¿Cómo funciona una Syscall?</summary>
  <ol>
    En un sistema operativo Linux, la syscall funciona como una puerta de enlace entre el programa de usuario y el núcleo del sistema operativo. Cuando un programa necesita acceder a un recurso o servicio del sistema operativo, genera una interrupción de software a través de una syscall. Esta interrupción cambia el sistema del modo de usuario al modo de núcleo, permitiendo al programa interactuar de manera segura con el núcleo del sistema operativo.

El proceso exacto es el siguiente: Primero, el programa coloca los argumentos de la syscall en los registros del procesador. Luego, el programa realiza la syscall, que se implementa como una interrupción de software. Esta interrupción cambia el sistema del modo de usuario al modo de núcleo. Una vez en el modo de núcleo, el sistema operativo examina los argumentos de la syscall y determina qué servicio o recurso del sistema operativo se está solicitando. Luego, el sistema operativo ejecuta la operación solicitada, coloca el resultado en un lugar donde el programa pueda acceder a él (generalmente otro registro del procesador), y finalmente devuelve el control al programa de usuario.

Cada syscall tiene asociado un número único que el sistema operativo usa para identificar qué servicio o recurso se está solicitando. Los programas suelen utilizar una biblioteca de funciones, como la biblioteca de C de Unix (glibc), que proporciona funciones de alto nivel que a su vez realizan las syscalls necesarias.

Es importante recordar que, aunque este es el mecanismo general de cómo funcionan las syscalls en Linux, los detalles específicos pueden variar dependiendo de la arquitectura del procesador y la versión del sistema operativo.
  </ol>
</details>

# Problema 1: Verificación de Expresiones Aritméticas
El objetivo de este problema es desarrollar una función que determine si una expresión aritmética está correctamente cerrada en cuanto a paréntesis y corchetes. Para ello, se debe implementar una llamada al sistema (system call) en el kernel de Linux y crear un programa que haga uso de esta llamada para verificar expresiones aritméticas.

## Implementación de la System Call
La función de verificación de expresiones aritméticas se implementará como una system call en el kernel de Linux. El proceso para agregar esta system call implica los siguientes pasos:

1. Implementación de la Función en el Kernel: Se desarrollará una función en el código fuente del kernel que llevará a cabo la verificación de la expresión aritmética. Esta función recibirá como parámetro un puntero a la cadena que contiene la expresión y retornará un valor booleano indicando si la expresión está correctamente cerrada o no.
2. Definición de la System Call: Se definirá una nueva system call en el kernel, que será el punto de entrada para invocar la función de verificación desde el espacio de usuario.
3. Compilación del Kernel: Se recompilará el kernel de sistema operativo para incorporar la nueva system call.


# Problema 2: Producto Punto de Vectores

El segundo problema consiste en desarrollar una función que calcule el producto punto de dos vectores de tamaño n. Esta función se implementará como una system call en el kernel de Linux, y se creará un programa de usuario que haga uso de esta system call para calcular el producto punto de dos vectores dados.

## Implementación de la System Call
La función de cálculo del producto punto de vectores se implementará como una system call en el kernel de Linux. El proceso para agregar esta system call será similar al descrito para el Problema 1.

## Pasos para compilar el Kernel (sin cambios)
1. Instalar una distribución estable de Linux (Ubuntu)
2. Descargar VirtualBox
3. Montar la imagen asegurarse de darle el espacio de memoria y disco necesario
4. Verificar en consola la versión de su distro para descargar el código fuente `lsb_release -a`
5. Verificar la versión del Kernel `uname -r`
6. Descargar el código de una versión igual o superior de la distribución seleccionada.
7. Se debe de descargar todo el código en la carpeta usr/src
8. Correr los siguintes comandos:
   ```bash
   a.	sudo apt-get install gcc
   b.	sudo apt-get install libncurses5-dev
   c.	sudo apt-get install bison
   d.	sudo apt-get install flex
   e.	sudo apt-get install libssl-dev
   f.	sudo apt-get install libelf-dev
   g.	sudo apt-get update
   h.	sudo apt-get upgrade
   ```
9. Compilar el Kernel
    ```bash
    a.	sudo make menuconfig
    b.	sudo make –j(# de procesadores a usar)
    ```
    
10. Para instalar su versión: `sudo make modules_install install`
   
11. Verificar que compiló correctamente: `uname –r`


## Pasos para compilar el Kernel modificado (con las nuevas Syscalls)
.......
.......
.......
.......
.......

## Diagrama conceptual Usuario - System Call

```mermaid
graph TD;
    subgraph Proceso_de_Usuario
        A[Inicio] --> B[Llamada a System Call]
    end
    subgraph Sistema_Operativo
        B --> C[Transición al Modo Kernel]
        C --> D[Verificación de Syscall y Permisos]
        D --> E[Recuperación de Parámetros]
        E --> F[Validación de Memoria]
        F --> G[Ejecución de Función de Syscall]
        G --> H[Generación de Resultado]
        H --> I[Retorno al Espacio de Usuario]
    end
    subgraph Proceso_de_Usuario
        I --> J[Muestra Resultado al Usuario]
    end

    style G fill:#110f85;

```

## Se agregan las Syscalls nuevas a la tabla de syscalls del kernel
![image](https://github.com/nickolasnolte1/OS-SysCall/assets/61555652/6dedc58d-d9a3-4265-860c-8a7c287dc63e)





## Autores (UFM)
- Marcela Melgar
- Nickolas Nolte
- Jose Reyes
- Esteban Samayoa
