

// Opciones de configuración:
	char ssid[10]		= "FEALAC Hg";	// Nombre para el modulo Bluetooth.
	char baudios		 = '4';		   // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (por defecto), 5=>19200, 6=>38400, 7=>57600, 8=>115200
	char password[10]	= "0000";		// Contraseña para el emparejamiento del modulo.


void setup()
{
	Serial.begin(9600);
	
	// Tiempo de espera:
		pinMode(13,OUTPUT);
		digitalWrite(13,HIGH);
		delay(10000);
		digitalWrite(13,LOW);
	
	// Ahora se procede a la configuración del modulo:
	
		// Se inicia la configuración:
			Serial.print("AT"); delay(1000);

		// Se ajusta el nombre del Bluetooth:
			Serial.print("AT+NAME"); Serial.print(ssid); delay(1000);

		// Se ajustan los baudios:
			Serial.print("AT+BAUD"); Serial.print(baudios); delay(1000);

		// Se ajusta la contraseña:
			Serial.print("AT+PIN"); Serial.print(password); delay(1000);	
}

void loop()
{
	// Al parpadear el led se habrá terminado la configuración:
	digitalWrite(13, !digitalRead(13));
	delay(500);
}
