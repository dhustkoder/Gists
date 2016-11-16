#!/bin/lua

local errors = nil
local word = nil
local hiddenWord = nil
local tries = nil
local body = nil
local words = { 
	"computer", "nintendo", 
	"commodore", "linux" 
}

function incErrors()
	errors = errors + 1
	if errors == 1 then body.head = "( )"
	elseif errors == 2 then body.rightarm = "/"
	elseif errors == 3 then body.chest = "|"
	elseif errors == 4 then body.leftarm = "\\"
	elseif errors == 5 then body.rightleg = "/"
	elseif errors == 6 then body.leftleg = "\\"
	end
end

function drawPole()
	os.execute("clear")
	print("________\n" ..
	      "|      |\n" ..
	      "|     " .. body.head .. "\n" ..
	      "|     " .. body.rightarm .. body.chest .. body.leftarm .. "\n" ..
	      "|     " .. body.rightleg .. " " .. body.leftleg .. "\n" ..
	      "|     ")
	for i = 1, #hiddenWord do
		io.write(hiddenWord:sub(i, i) .. " ")
	end
	io.write("\n")
end

function initGame()
	errors = 0
	tries = {}
	body = {
		head = "", rightarm = "", chest = "",
		leftarm = "", rightleg = "", leftleg = "" 
	}

	local count = 0
	for i, k in ipairs(words) do
		count = count + 1
	end

	math.randomseed(os.time())
	word = words[math.random(1, count)]
	hiddenWord = ""
	for i = 1, #word do
		hiddenWord = hiddenWord .. "_"
	end
	drawPole()
end

function updateGame()
	io.write("enter a character: ")
	local c = io.read()
	if tries[c] == true then
		print("you already tried that character")
		return false
	end

	tries[c] = true
	local found = false
	for i = 1, #word do
		if c == word:sub(i, i) then
			found = true
			hiddenWord = hiddenWord:sub(1, i-1)
			.. c .. hiddenWord:sub(i+1)
		end
	end
	if found == false then 
		incErrors() 
	end
	drawPole()
	return hiddenWord == word and true or false
end

while true do
	initGame()
	while updateGame() == false and errors < 6 do end
	print(errors < 6 and "YOU WON" or "YOU LOSE")
	print("play again ? y/n")
	local answer = io.read()
	if answer ~= 'y' then 
		break 
	end
end














