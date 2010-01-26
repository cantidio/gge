dofile("data/character/class_character.lua")
dofile("data/player/class_input.lua")

--[[
	-- Classe que representa um jogador
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	26/01/2010
-]]
function Player(pPointer)
	this 		= {}
	this 		= Character(pPointer,nil)
	this.mInput	= Input()
	
	return this
end

