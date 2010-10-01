print("include: GGE_Player")
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
	--			A classe de jogador È a mesma classe GGE_Object sÛ com possibilidade
	-- de leitura da entrada de dados do jogador
-]]
function GGE_Player(pSprite, pAnimation, pLayer)
	GGE_game_log("GGE_Player()")
	local this	= {}
	this 		= GGE_Object( pSprite, pAnimation, pLayer )
	this.mInput	= GGE_Input()
	
	return this
end

