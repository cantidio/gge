print("include: GGE_Game")
--[[
	-- Classe que representa o jogo
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	30/09/2010
	-- @version	20/10/2010
-]]
GGE_Game = class(
	function (self)
		GGE_game_log("GGE_Game()")

		self.mName			= ""
		self.mVersion		= "0.0"
		self.debugWindow	= true -- não sei o que fazer com isso ainda. kkkk
		self.mVideo			= {
			width			= 320,
			height			= 240,
			FPS				= 60,
			fullScreen		= false,
		}
		self.mWindow		= {
			logo			= "",
			title			= "",
		}
	end
)
--[[
	--Método para iniciar o vídeo do engine
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	29/09/2010
-]]
function GGE_Game:init()
	GGE_game_log("GGE_Game():init()")
	
	if not GGE_game_setFPS(self.mVideo.FPS)		or
	not GGE_game_setGameName(self.mName)		or
	not GGE_game_setGameVersion(self.mVersion)	or
	not GGE_game_init( 							--inicia o vídeo, o input e o audio*
		self.mWindow.title,
		self.mVideo.width,
		self.mVideo.height,
		self.mVideo.fullScreen
	) then
		return false
	end
	
	GGE_game_log("GGE_Game():~init()")
	return true
end
--[[
	-- Método chamado a cada iteraćão do jogo
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	01/10/2010
	-- @version	01/10/2010
-]]
function GGE_Game:logic()
	self:state()
end

function GGE_Game:state() end


--[[
	-- Funcão para executar um passo da lógica do game
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	30/09/2010
	-- @version	20/10/2010
-]]
function GGE_game_runStep()
	this:logic()
end

