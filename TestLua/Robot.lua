-- Write lua code below :)
Robot = {}

function Robot:OnInit()
	print("BEEP BEEP, STARTING...")
end

function Robot:Speak()
	print("BEEP BEEP, I'M SPEAKING !")
end

function Robot:Sing()
	print("BEEP BEEP I'M A SHEEP, I SAID BEEP BEEP I'M A SHEEP")
end

function Robot:RandomSpeak()
	local lang = math.random(0, 2)

	if lang == 0 then
		self:SpeakItalian() 
	elseif lang == 1 then
		self:SpeakHylian()
	else
		self:SpeakLatin()
	end

end

