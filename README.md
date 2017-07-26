# GD23STM32_F103

Librería para MCU´s STM32F103. Lector SdFat y pantallas http://hotmcu.com o Riverdi
FTDI chip FT8XXQ funcionan correctamente. Toda la familia F103 de STM32 a 72MHz funciona correctamente.

Pantalla FT8XX en SPI1, lector microSD en SPI2.

# Calibración de la pantalla FT8XX

Es conveniente tener instalado una EEPROM externa tipo 24C32 (NUNCA INFERIOR) sea 24C64 o mayor. la direccion de la EEPROM se define en el fichero GD23STM32.cpp localizando la linea; 

<b>#define i2c_address 0x50</b>

