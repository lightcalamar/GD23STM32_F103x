# LICENCIA / LICENSE

Team FT81X ( @TFTLCDCyg, @lightcalamar and @RndMnkIII )

http://forum.arduino.cc/index.php?topic=419836.0
http://forum.arduino.cc/index.php?topic=406170.0
http://forum.arduino.cc/index.php?topic=445405.0

Librería basada en GD2 Arduino DUE de James Bowman; http://excamera.com/files/Gameduino2_Due.zip  --ARM 32 bit---

http://gameduino2.proboards.com/thread/367/new-team-ft81x

 * Copyright (C) 2013-2016 by James Bowman <jamesb@excamera.com>
 * Gameduino 2 library for Arduino, Arduino Due, Raspberry Pi.


# GD23STM32_F103

Librería para MCU´s STM32F103. Lector SdFat y pantallas http://hotmcu.com o Riverdi
FTDI chip FT8XXQ funcionan correctamente. Toda la familia F103 de STM32 a 72MHz funciona correctamente.

Pantalla FT8XX en SPI1, lector microSD en SPI2.

# Calibración de la pantalla FT8XX

Es conveniente tener instalado una EEPROM externa tipo 24C32 (NUNCA INFERIOR) sea 24C64 o mayor. la direccion de la EEPROM se define en el fichero GD23STM32.cpp localizando la linea; 

<b>#define i2c_address 0x50</b>

