dofile("data/character/class_character.lua")
dofile("data/character/player/class_input.lua")

--[[
	-- Classe que representa um jogador
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	30/09/2010
	-- @param	string 		pSprite		, pacote de sprites a ser usado
	-- @param	string		pAnimation	, pacote de anima√√es a ser usado
	-- @param	GGE_Layer	pLayer		, layer o qual o player se encontra
	-- @details
	--			A classe de jogador √© a mesma classe deGGE_Object s√≥ que com possibilidade
	-- de leitura da entrada de dados do jogador
-]]
function GGE_Player(pSprite, pAnimation, pLayer)
	local this	= {}
	this 		= GGE_Object( pSprite, pAnimation, pLayer )
	this.mInput	= GGE_Input()
	
	return this
end

