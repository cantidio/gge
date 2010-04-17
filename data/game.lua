function Game()
	local this = { }
	
	this.mName				= "nome do jogo"
	this.mVersion			= "0.0"

	this.debugWindow		= true
	this.mFramePerSeconds	= 60
	this.mScreen.width		= 200
	this.mScreen.height		= 160
	this.mScreen.windowed	= true
	
	this.mWindow.logo		= ""
	this.mWindow.title		= "titulo da janela"
	
	
	local function init()
		lua_game_setName()
		lua_game_setVersion()
		lua_game_setFramePerSeconds()
	end
	--[[
		-- Método chamado a cada iteraćão do jogo
	-]]
	local function logic()
		this.state()
	end
	
	player = new(Player())
	
	function new(pClass)
		pClass.cppCreate()
		
		local function cppCreate()
			this.mPointer = lua_player_create()
		end
		
		return pClass
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
	
	local function stateMenuInit()
		this.background = Background("data/background/menu.lua")
		this.player		= Player("data/player/menu_player.lua")
		this.state		= this.stateMenu
	end
	
	local function stateMenu()
		this.background.logic()
		this.player.logic()
		this.background.draw()
		this.player.draw()
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
		
		pGui.draw()
	end
	
end

