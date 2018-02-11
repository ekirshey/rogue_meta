import os
import msvcrt as m
from subprocess import call

with open(os.devnull, "w") as f:
		call(["cl", "/EHsc", "src/main.cpp", "/DKEYBOARD_INPUT=\"\"", "/std:c++latest", "/link"], stdout=f, stderr=f)

while True:
	os.system('cls')
	call("main.exe")
	playerinput = input("")
	if playerinput == "quit":
		exit()

	with open(os.devnull, "w") as f:
		call(["cl", "/EHsc", "src/main.cpp", "/DKEYBOARD_INPUT=\""+playerinput+"\"", "/std:c++latest", "/link"], stdout=f, stderr=f)

