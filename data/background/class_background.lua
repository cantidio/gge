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
	-- @version	17/12/1009
	-- @param	int pPointer, endereço do cenário na memória
-]]
function Background(pPointer)
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
		-- @version	17/12/2009
		-- @return	int
	-]]
	local function getLayerNumber()
		return lua_background_getLayerNumber(this.pointer)
	end

	--[[
		-- Método que retorna o arquivo de script do layer indicado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	17/12/2009
		-- @param	int index, índice do layer
		-- @return	string
	-]]
	local function getLayer(pIndex)
		local layer = Layer(lua_background_getLayer(this.pointer,pIndex - 1));
		return layer;
	end
	--[[
		-- Método que retorna a largura do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	02/01/2010
		-- @version	02/01/2010
		-- @return	int
	-]]
	local function getWidth()
		return lua_background_getWidth(this.pointer)
	end
	--[[
		-- Método que retorna a altura do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	02/01/2010
		-- @version	02/01/2010
		-- @return	int
	-]]
	local function getHeight()
		return lua_background_getHeight(this.pointer)
	end

	--[[
		-- Método que retorna a posição atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @return	{x,y}
	-]]
	local function getPosition()
		local X,Y = lua_background_getPosition(this.pointer)
		return {x = X, y = Y}
	end

	--[[
		-- Método que seta a posição atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	{x,y} pPosition, nova posição do cenário
	-]]
	local function setPosition(pPosition)
		lua_background_setPosition(
			this.pointer,
			pPosition.x,
			pPosition.y
		)
	end

	--[[
		-- Método que adiciona um valor a posição do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	int pPosition, valor a ser adicionado a posição do cenário
	-]]
	local function addPosition(pPosition)
		lua_background_addPosition(
			this.pointer,
			pPosition.x,
			pPosition.y
		)
	end

	--[[
		-- Método que subtrai um valor a posição x do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	{x,y} pPosition, valor a ser subtraído da posição do cenário
	-]]
	local function subPosition(pPosition)
		lua_background_subPosition(
			this.pointer,
			pPosition.x,
			pPosition.y
		)
	end

	--[[
		-- Método que trava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	local function scrollLock()
		lua_background_scrollLock(this.pointer)
	end

	--[[
		-- Método que destrava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	local function scrollUnlock()
		lua_background_scrollUnlock(this.pointer)
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
	this.getWidth		= getWidth
	this.getHeight		= getHeight
	this.getPosition	= getPosition
	this.setPosition	= setPosition
	this.addPosition	= addPosition
	this.subPosition	= subPosition
	this.scrollLock		= scrollLock
	this.scrollUnlock	= scrollUnlock
	this.finished		= finished
	this.logic			= logic

	--Memory Address for the background class that called the script
	this.pointer			= pPointer
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

