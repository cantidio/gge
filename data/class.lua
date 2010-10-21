print("include: GGE_Class")
--[[
	-- Function that creates a class
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/10/2010
	-- @version	20/10/2010
	-- @param	function const, the constructor of the class
	-- @param	table base, the class base, can be nil
	-- @return	table

function class(const, base)
	local this = { }
	local mt = { __index = this }
	
	if base then
		setmetatable( this, {__index = base} )
		for key, value in pairs(base) do
			--print("key: " .. key .. "type: " .. type(value))
			this[key] = value
		end
		this.super = base
	end
	
	this.constructor = const
	this.__dir = _SCRIPT_LOCATION_
	
	this.new = function (class, ...)
		local newinst = { }
		setmetatable(newinst, mt )
		if const then
			const(newinst, ...)
		end
		return newinst
	end
	return this
end
-]]

function class()
	local self = {}
	self.__dir = _SCRIPT_LOCATION_
	return self
end

