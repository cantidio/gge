dofile("players.lua")
dofile("backgrounds.lua")
function Game()
	local this = { }

	this.mName				= ""
	this.mVersion			= "0.0"
	this.debugWindow		= true -- não sei o que fazer com isso ainda. kkkk

	this.mVideo		= {
		width		= 320,
		height		= 240,
		FPS			= 60,
		fullScreen	= true,
	}

	this.mWindow.logo		= ""
	this.mWindow.title		= ""


	--[[
		--Método para iniciar o vídeo do engine
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
	-]]
	this.init = function()
		if not GGE_init( --inicia o vídeo, o input e o audio*
			this.mWindow.title,
			this.mVideo.width,
			this.mVideo.height,
			this.mVideo.fullScreen
		)										or 
		not GGE_setGameName(this.mName)			or
		not GGE_setGameVersion(this.mVersion)	or
		not GGE_setFPS(this.mVideo.FPS)			then
			return nil
		end
		return true
	end
	
	--[[
		-- MÃ©todo chamado a cada iteraÄ‡Ã£o do jogo
	-]]
	this.logic = function()
		this.state()
	end


	local function getNextMission(pBackground,pPlayer)
		if pBackground.name == "jonas" then
			if pBackground.Flag == 1 then

				this.state = this.stateMission2Init
			else
				this.state = this.stateMission3Init
			end
		else
			this.state = this.stateMission4Init
		end
		pBackground.clear()

	end

	local function stateDisclaimerInit()
		this.background = Background("data/background/disclaimer.lua")
		this.time		= 0
		this.state = this.stateDisclaimer
	end

	local function stateDisclaimer()
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

	local function stateMenu()
		this.background.logic()
		this.background.draw()
	end

	local function stateNewGameInit()
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

end

