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
-]]
function class(const, base)
	local this = {}
	local mt = { __index = this }
	this.constructor = const
	this.new = function (class, ...)
		local newinst = {}
		setmetatable(newinst, mt )
		if const then
			const(newinst,...)
		end
		return newinst
	end

	if base then
		setmetatable( this, {__index = base} )
		this.super = base
	end
	return this
end
