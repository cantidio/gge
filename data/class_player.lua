print("include: GGE_Player")
GGE_Player = class()
--[[
	-- Classe que representa um jogador
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	22/10/2010
	-- @param	string 		pSprite		, pacote de sprites a ser usado
	-- @param	string		pAnimation	, pacote de anima��es a ser usado
	-- @param	GGE_Layer	pLayer		, layer o qual o player se encontra
	-- @details
	--			A classe de jogador � a mesma classe GGE_Object s� com possibilidade
	-- de leitura da entrada de dados do jogador
-]]
function GGE_Player:new(
	pSpritePack,
	pAnimationPack,
	pLayer,
	pPosition
)
	local self = GGE_Object:new(
		pSpritePack,
		pAnimationPack,
		pLayer,
		pPosition
	)
	self.mInput	= GGE_Input:new()
	return self
end

