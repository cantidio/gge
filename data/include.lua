print("include: GGE_Include")
_SCRIPT_LOCATION_ = ""

function string:split(pattern, start)
	if start == nil then start = 1 end
	local t = {}
	local a, b = self:find(pattern, start)

	while a and b do
		if a - 1 > 0 then
			t[#t + 1]	= self:sub(start, a - 1)
		end
		start		= b + 1
		a, b		= self:find(pattern, start)
	end
	
	if start < #self then
		t[#t + 1]	= self:sub(start,#self)
	end
	return t
end

function include(script)
	local thisLocation	= _SCRIPT_LOCATION_
	local location		= script:split("/")
		
	for i = 1, #location - 1 do
		_SCRIPT_LOCATION_ = _SCRIPT_LOCATION_ .. location[i] .. "/"
	end
	print("include: " .. _SCRIPT_LOCATION_ .. location[#location])
	GGE_game_log("include: " .. _SCRIPT_LOCATION_ .. location[#location])
	dofile(_SCRIPT_LOCATION_ .. location[#location] )
	
	_SCRIPT_LOCATION_ = thisLocation
end

