Driver.cpp: interacts and collects data through terminal, user can set a passkey, encrypt/decrypt the text, view text history and log of all actions.
	g++ driver.cpp -o driver
	./driver log.txt
	output will be saved in mylog.txt

Encryptor.cpp: uses Vigenère cipher algorithm to encrypt/decrypt messages, it reads commands from inputs.
	g++ encryptor.cpp -o encryptor

Logger.cpp: logs messages to a file, with prefixed and formatted timestamp. It reads action by the format: ACTION message
	g++ logger.cpp -o logger
	./logger log.txt
	output will be saved in logfile.txt