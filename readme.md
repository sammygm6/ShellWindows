Indicaciones
1. No debe usar los comandos ya creados ni las funciones de la consola. Usted debe codificar los comandos usando las llamadas al sistema del sistema operativo. No se puede usar la función system(). Cada comando es un proceso (tiene que crear el programa).
2. Para la tubería y el redireccionamiento debe usar las llamadas al sistema de tuberias
3. Cada estudiante debe programar el 25% del proyecto. No se acepta que el estudiante SOLAMENTE haya investigado. Cada estudiante debe programar mínimo 4 comandos. Se hará una defensa para confirmar su programación.
Descripción del proyecto
Diseñe la consola mi_sh> de manera que
1. lea un comando [comando [opciones]] y valide si existe o no. Si existe ejecute el comando sino imprima “comando no encontrado”. Debe interpretar cada una de las opciones del comando
Mi_sh> ls –l –m [ninguna o cualquiera de las opciones]
Los comandos GUI los puede correr en el background o en el foreground (&)
Por ejemplo
Mi_sh>notepad.exe& // La consola continua ejecutando comandos
Mi_sh>notepad.exe // La consola se bloquea hasta que el comando finaliza
2. Se puedan crear tuberías usando la siguiente sintaxis
Comando1 argumentos1 | Comando2 argumentos2 |…| Comandom argumentosm
3. Se puede re-direccionar la entrada estándar, la salida estándar a un archivo.
Operadores de redireccionamiento: >, <
Por ejemplo
Mi_sh>cat > a.txt // La entrada estándar (el teclado) se copia en el archivo
