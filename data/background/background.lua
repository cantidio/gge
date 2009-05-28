--background
--Memory Address for the background class that called the script
backgroundPointer	= nil
--Background gravity
gravity				= 0
--Friction when not coliding
voidFriction		= 1
--width of the background
width				= 0
--height of the background
height				= 0
--init x position
posX				= 0
--init y position
posY				= 0
--vector with the layers of the background
layers				= { }
--player information
player				= {
	script		= "",
	layer		= 1,
	xPosition	= 0,
	yPosition	= 0,
--	mirroring	= mirroring.Normal,
	initialState= 290 
}
-- Função para registrar o ponteiro do cenário que invocou o script
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	20/03/2009
-- @param	int pointer, endereço do cenário na memória
function setBackgroundPointer(pointer)
	backgroundPointer=pointer
end

-- Função que retorna o número de layers que o cenário possui
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @return	int
function getLayerNumber()
	return #layers;
end

-- Função que retorna o arquivo de script do layer indicado
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int index, índice do layer
-- @return	string
function getLayer(index)
	return layers[index];
end

-- Função que retorna a posição x atual do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	20/03/2009
-- @return	int
function getXPosition()
	return lua_getXPosition(backgroundPointer)
end

-- Função que retorna a posição y atual do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	20/03/2009
-- @return	int
function getYPosition()
	return lua_getYPosition(backgroundPointer)
end

-- Função que seta a posição x atual do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int pPosX, nova posição x
function setXPosition(pPosX)
	lua_setXPosition(backgroundPointer,pPosX)
end

-- Função que seta a posição y atual do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int pPosY, nova posição y
function setYPosition(pPosY)
	lua_setYPosition(backgroundPointer,pPosY)
end

-- Função que adiciona um valor a posição x do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int pPosX, valor a ser adicionado a posição x
function addXPosition(pPosX)
	lua_addXPosition(backgroundPointer,pPosX)
end

-- Função que adiciona um valor a posição y do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int pPosY, valor a ser adicionado a posição y
function addYPosition(pPosY)
	lua_addYPosition(backgroundPointer,pPosY)
end

-- Função que subtrai um valor a posição x do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int pPosX, valor a ser subtraído da posição x
function subXPosition(pPosX)
	lua_subXPosition(backgroundPointer,pPosX)
end

-- Função que subtrai um valor a posição y do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int pPosY, valor a ser subtraído da posição y
function subYPosition(pPosY)
	lua_subYPosition(backgroundPointer,pPosY)
end

-- Função que trava o scrolling do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int x, valor a ser adicionado a posição x
function scrollLock()
	lua_scrollLock(backgroundPointer)
end

-- Função que destrava o scrolling do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
-- @param	int x, valor a ser adicionado a posição x
function scrollUnlock()
	lua_scrollUnlock(backgroundPointer)
end

-- Função que retorna se o cenário foi concluído
--
-- @author	Cantidio Oliveira Fontes
-- @since	19/03/2009
-- @version	19/03/2009
function finished()
	return false;
end

-- Função que executa a lógica do cenário
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
function logic()
	--put your logic here
end

