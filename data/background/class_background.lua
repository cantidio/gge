dofile("data/background/class_layer.lua")
--[[
	-- Função para registrar o ponteiro do cenário que invocou o script
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	15/12/2009
	-- @param	int pPointer, endereço do cenário na memória
-]]
function script_background_setPointer(pPointer)
	this.pointer = pPointer
end
--[[
	-- Função para retornar a gravidade do cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	15/12/2009
	-- @version	15/12/2009
	-- @return	double
-]]
function script_background_getGravity()
	return this.gravity
end
--[[
	-- Função para retorar a fricão no vácuo do cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	15/12/2009
	-- @version	15/12/2009
	-- @return	double
-]]
function script_background_getVoidFriction()
	return this.voidFriction
end
--[[
	-- Função para retornar a largura do cenario
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	15/12/2009
	-- @version	15/12/2009
	-- @return	int
-]]
function script_background_getWidth()
	return this.width
end
--[[
	-- Função para retornar a altura do cenario
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	15/12/2009
	-- @version	15/12/2009
	-- @return	int
-]]
function script_background_getHeight()
	return this.height
end
--[[
	-- Função para retornar a posicão X inicial do cenario
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	15/12/2009
	-- @version	15/12/2009
	-- @return	int
-]]
function script_background_getPosX()
	return this.posX
end
--[[
	-- Função para retornar a posicão Y inicial do cenario
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	15/12/2009
	-- @version	15/12/2009
	-- @return	double
-]]
function script_background_getPosY()
	return this.posY
end
--[[
	-- Função que retorna o número de layers que o cenário possui
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	15/12/2009
	-- @return	int
-]]
function script_background_getLayerNumber()
	return #this.layers;
end
--[[
	-- Função que retorna o arquivo de script do layer indicado
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	15/12/2009
	-- @param	int index, índice do layer
	-- @return	string
-]]
function script_background_getLayer(index)
	return this.layers[index];
end
--[[
	-- Função que retorna se o cenário foi concluído
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	15/12/2009
-]]
function script_background_finished()
	return this.finished();
end
--[[
	-- Função que executa a lógica do cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	15/12/2009
-]]
function script_background_logic()
	this.logic()
end
---------------------------------------------------------------------------------------------------------------------------------------------------------
--[[
	-- Classe que representa um cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	14/12/1009
-]]
function Background()
	local this = { }
	--[[
		-- Método para registrar o ponteiro do cenário que invocou o script
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	20/03/2009
		-- @param	int pPointer, endereço do cenário na memória
	-]]
	local function setPointer(pPointer)
		this.pointer = pPointer
	end

	--[[
		-- Método que retorna o número de layers que o cenário possui
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @return	int
	-]]
	local function getLayerNumber()
		return lua_getLayerNumber(this.pointer)
	end

	--[[
		-- Método que retorna o arquivo de script do layer indicado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int index, índice do layer
		-- @return	string
	-]]
	local function getLayer(pIndex)
		local layer = Layer();
		layer.setPointer(lua_getLayer(this.pointer,pIndex-1));
		return layer;
	end

	--[[
		-- Método que retorna a posição x atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	20/03/2009
		-- @return	int
	-]]
	local function getXPosition()
		return lua_getXPosition(this.pointer)
	end

	--[[
		-- Método que retorna a posição y atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	20/03/2009
		-- @return	int
	-]]
	local function getYPosition()
		return lua_getYPosition(this.pointer)
	end

	--[[
		-- Método que seta a posição x atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int pPosX, nova posição x
	-]]
	local function setXPosition(pPosX)
		lua_setXPosition(this.pointer,pPosX)
	end

	--[[
		-- Método que seta a posição y atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int pPosY, nova posição y
	-]]
	local function setYPosition(pPosY)
		lua_setYPosition(this.pointer,pPosY)
	end

	--[[
		-- Método que adiciona um valor a posição x do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int pPosX, valor a ser adicionado a posição x
	-]]
	local function addXPosition(pPosX)
		lua_addXPosition(this.pointer,pPosX)
	end

	--[[
		-- Método que adiciona um valor a posição y do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int pPosY, valor a ser adicionado a posição y
	-]]
	local function addYPosition(pPosY)
		lua_addYPosition(this.pointer,pPosY)
	end

	--[[
		-- Método que subtrai um valor a posição x do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int pPosX, valor a ser subtraído da posição x
	-]]
	local function subXPosition(pPosX)
		lua_subXPosition(this.pointer,pPosX)
	end

	--[[
		-- Método que subtrai um valor a posição y do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int pPosY, valor a ser subtraído da posição y
	-]]
	local function subYPosition(pPosY)
		lua_subYPosition(this.pointer,pPosY)
	end

	--[[
		-- Método que trava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int x, valor a ser adicionado a posição x
	-]]
	local function scrollLock()
		lua_scrollLock(this.pointer)
	end

	--[[
		-- Método que destrava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
		-- @param	int x, valor a ser adicionado a posição x
	-]]
	local function scrollUnlock()
		lua_scrollUnlock(this.pointer)
	end

	--[[
		-- Método que retorna se o cenário foi concluído
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	local function finished()
		return false;
	end

	--[[
		-- Método que executa a lógica do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	18/03/2009
	-]]
	local function logic()
	end

	this.setPointer		= setPointer
	this.getLayerNumber	= getLayerNumber
	this.getLayer		= getLayer
	this.getXPosition	= getXPosition
	this.getYPosition	= getYPosition
	this.setXPosition	= setXPosition
	this.setYPosition	= setYPosition
	this.addXPosition	= addXPosition
	this.addYPosition	= addYPosition
	this.subXPosition	= subXPosition
	this.subYPosition	= subYPosition
	this.scrollLock		= scrollLock
	this.scrollUnlock	= scrollUnlock
	this.finished		= finished
	this.logic			= logic

	--Memory Address for the background class that called the script
	this.pointer			= nil
	--Background gravity
	this.gravity			= 0
	--Friction when not coliding
	this.voidFriction		= 1
	--width of the background
	this.width				= 0
	--height of the background
	this.height				= 0
	--init x position
	this.posX				= 0
	--init y position
	this.posY				= 0
	--vector with the layers of the background
	this.layers				= { }
	--player information
	this.player				= {
		script		= "",
		layer		= 1,
		xPosition	= 0,
		yPosition	= 0,
	--	mirroring	= mirroring.Normal,
		initialState= 290 
	}
	return this
end

