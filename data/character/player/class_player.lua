dofile("data/character/class_character.lua")
dofile("data/character/player/class_input.lua")

--[[
	-- Classe que representa um jogador
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	26/01/2010
	-- @details
	--			A classe de jogador é a mesma classe de Character só que com possibilidade
	-- de leitura da entrada de dados do jogador
-]]
function Player(pPointer)
	local this	= { }
	this 		= Character(pPointer,nil)
	this.mInput	= Input()
	
	return this
end

