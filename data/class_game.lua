print("include: GGE_Game")
--[[
	-- Classe que representa o jogo
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	
	-- @version	30/09/2001
-]]
function GGE_Game()
	GGE_game_log("GGE_Game()")
	
	local this 			= { }
	this.mName			= ""
	this.mVersion		= "0.0"
	this.debugWindow	= true -- não sei o que fazer com isso ainda. kkkk
	this.mVideo			= {
		width			= 320,
		height			= 240,
		FPS				= 60,
		fullScreen		= false,
	}
	this.mWindow		= {
		logo			= "",
		title			= "",
	}
	--[[
		--Método para iniciar o vídeo do engine
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
	-]]
	this.init = function()
		GGE_game_log("GGE_Game().init()")
		
		if not GGE_game_setFPS(this.mVideo.FPS)		or
		not GGE_game_setGameName(this.mName)		or
		not GGE_game_setGameVersion(this.mVersion)	or
		not GGE_game_init( 							--inicia o vídeo, o input e o audio*
			this.mWindow.title,
			this.mVideo.width,
			this.mVideo.height,
			this.mVideo.fullScreen
		) then
			return nil
		end
		return true
	end
	--[[
		-- Método chamado a cada iteraćão do jogo
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	01/10/2010
	-]]
	this.logic = function()
		this.state()
	end

--[[	this.stateDisclaimerInit = function()
		this.background = Background("data/background/disclaimer.lua")
		this.time		= 0
		this.state = this.stateDisclaimer
	end

	this.stateDisclaimer = function()
		this.background.logic()
		this.background.draw();
		this.time = this.time + 1

		if time >= 60 then
			this.state = this.stateMenuInit
			this.background.clear()
		end

	end

	this.stateMenuInit = function()
		this.background = Background("data/background/menu.lua")
		this.player		= Player("data/player/menu_player.lua")
		this.state		= this.stateMenu
		
		this.background.addObject(this.player)
		this.background.setCamera(this.player,{x=0,y=0})
		
	end

	this.stateMenu = function()
		this.background.logic()
		this.background.draw()
	end

	this.stateNewGameInit = function ()
		dofile("data/mission.lua")
	end

	local function stateMission(pBackground,pPlayer)

		pBackground.logic()
		pPlayer.logic()
		pGui.logic()

		pBackground.draw()
		pPlayer.draw()
		
		cenario.setCamera(jogador+jogador2,{x=12,y=12})
		
		logic{
			move lanlanlanl
			desloca com a camera
			roda a lógica de todos os layers
				os layers rodam a lógica de todos objetos dentro deles
		}
		pGui.draw()
	end
-]]
	this.state = function() end
	return this
end

--[[
	-- Funcão para executar um passo da lógica do game
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	30/09/2010
	-- @version	01/10/2010
-]]
function GGE_game_runStep()
	this.logic()
end

