# Local-virtual-connections-unix
Отчет по лабораторной работе № 11 по курсу «Операционные системы». Локальные виртуальные соединения.

## Цель работы:
Целью выполнения настоящей лабораторной работы является получение навыков создания и использования локальных виртуальных соединений между процессами, используя метод сокетов. 

## Ход выполнения работы:
1. Создаем клиент `client.c` который будет выводить текст своего файла и `server.c`.
2. Также создаем второй клиент `client2.c` и все компилируем.
3. Запускаем сервер в оперативном режиме.
4. Запускаем два наших клиента в фоновом режиме передав в качестве параметра два разных файла.

Текст файла file:

```
Potlog
My first 
client
```

Текст файла file2:

```
My 2 client
 i am working
```

Результат работы программ:

`Cверху доп. Окно сервера. Снизу справа и слева два окна клиента.`

![rsult](https://i.imgur.com/VP80FoP.png)

Для того что бы понять где какой клиент, выводим `PID` каждого клиента.
После работы закрываем все ранее запущенные процессы.

## Вывод:
На практике получили навыки работы создания и использования  локальных виртуальных соединений между процессами при использовании метода сокетов.
На практике узнали чем отличается tcp от udp протокола.

## Источники.
[OCТУСУР](https://drive.google.com/file/d/17aHSL97aNbOCMYqPhJ3F1VB1V4il-stb/view?usp=sharing)


