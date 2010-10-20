print("include: GGE_Player")

--[[
	-- Classe que representa um jogador
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	20/10/2010
	-- @param	string 		pSprite		, pacote de sprites a ser usado
	-- @param	string		pAnimation	, pacote de anima√√es a ser usado
	-- @param	GGE_Layer	pLayer		, layer o qual o player se encontra
	-- @details
	--			A classe de jogador È a mesma classe GGE_Object sÛ com possibilidade
	-- de leitura da entrada de dados do jogador
-]]
GGE_Player = class(
	function(
		self,
		pSpritePack,
		pAnimationPack,
		pLayer,
		pPosition
	)
		GGE_game_log("GGE_Player.new()")
		--print("GGE_Player.new()")
		self.super:constructor(
			pSpritePack,
			pAnimationPack,
			pLayer,
			pPosition
		)
		self.mInput	= GGE_Input()
		GGE_game_log("GGE_Player.~new()")
		--print("GGE_Player.~new()")
	end,
	GGE_Object
)

