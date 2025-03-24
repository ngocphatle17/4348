Driver.cpp: interacts and collects data through terminal, user can set a passkey, encrypt/decrypt the text, view text history and log of all actions.
	g++ driver.cpp -o driver
	./driver mylog.txt
	output will be saved in mylog.txt

Encryptor.cpp: uses Vigenère cipher algorithm to encrypt/decrypt messages, it reads commands from inputs.
	g++ encryptor.cpp -o encryptor

Logger.cpp: logs messages to a file, with prefixed and formatted timestamp. It reads action by the format: ACTION message
	g++ logger.cpp -o logger
	./logger log.txt
	output will be saved in log.txt

The reason why I have 20 commits is because I did not commit during my implementing phases, which I was struggling the most, I know it is a bad habit and may lose my points for this projects, but I tried to commit and work through the project again. At first, I had 3 different txt files to contain the tests and outputs, but in my final submission, I have combined into one devlog file.
