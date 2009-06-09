
--
-- Classe para representar um Object em LUA
--
-- @author	Cantidio Oliveira Fontes
-- @since
-- @version	09/08/2009
--
function Object(pPointer)
	local obj = { }
	obj.pointer = pPointer
	
	-- Função para mudar a animação do objeto através de seu índice
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	09/06/2009
	-- @param	int pRealIndex, nova animação a trocar
	local function changeAnimationByIndex(pRealIndex)
		lua_changeAnimationByIndex(obj.pointer,pRealIndex)
	end
	
	-- Função para mudar a animação do objeto através do grupo e índice da mesma
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	09/06/2009
	-- @final	09/06/2009
	-- @param	int pGroup, grupo da nova animação
	-- @param	int pIndex, índice da nova animação
	local function changeAnimation(pGroup,pIndex)
		lua_changeAnimation(obj.pointer,pGroup,pIndex)
	end
	
	-- Função que retorna verdadeiro se a animação atual ainda está tocando
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @return	bool
	local function animationIsPlaying()
		return lua_animationIsPlaying(obj.pointer)
	end
	
	-- Função que retorna o número da animação que está tocando
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	14/03/2009
	-- @final	14/03/2009
	-- @return	int
	local function getAnimationOn()
		return lua_getAnimationOn(obj.pointer)
	end
	
	-- Função que retorna o número do frame atual da animação que está tocando
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	14/03/2009
	-- @final	14/03/2009
	-- @return	int
	local function getFrameOn()
		return lua_getFrameOn(obj.pointer)
	end
	
	-- Função para retornar a posiçãoX do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @return	int
	local function getXPosition()
		return lua_getXPosition(obj.pointer)
	end
	
	-- Função para retornar a posiçãoY do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @return	int
	local function getYPosition()
		return lua_getYPosition(obj.pointer)
	end
	
	-- Função para retornar a posição do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	31/03/2009
	-- @final	31/03/2009
	-- @return	table
	local function getPosition()
		return {x=getXPosition(),y=getYPosition()}
	end
	
	-- Função para setar a posiçãoX do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int x, posição x do objeto
	local function setXPosition(pPosX)
		lua_setXPosition(obj.pointer,pPosX)
	end
	
	-- Função para setar a posiçãoY do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int y, posição y do objeto
	local function setYPosition(pPosY)
		lua_setYPosition(obj.pointer,pPosY)
	end
	
	-- Função para setar a posição do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int x, posição x do objeto
	-- @param	int y, posição y do objeto
	local function setPosition(pPosX,pPosY)
		lua_setPosition(obj.pointer,pPosX,pPosY)
	end
	
	-- Função para adicionar um valor a posição x do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int x, valor a adicionar no eixo x do objeto
	local function addXPosition(pPosX)
		lua_addXPosition(obj.pointer,pPosX)
	end
	
	-- Função para adicionar um valor a posição y do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int y, valor a adicionar no exito y do objeto
	local function addYPosition(pPosY)
		lua_addYPosition(obj.pointer,pPosY)
	end
	
	-- Função para adicionar um valor a posição xy do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int x, valor a adicionar no eixo x do objeto
	-- @param	int y, valor a adicionar no eixo y do objeto
	local function addPosition(pPosX,pPosY)
		lua_addPosition(obj.pointer,pPosX,pPosY)
	end
	
	-- Função para subtrair um valor a posição x do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	31/03/2009
	-- @final	31/03/2009
	-- @param	double x, valor a subtrair no eixo x do objeto
	local function subXPosition(pPosX)
		lua_subXPosition(obj.pointer,pPosX)
	end
	
	-- Função para subtrair um valor a posição y do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	31/03/2009
	-- @final	31/03/2009
	-- @param	double y, valor a subtrair no exito y do objeto
	local function subYPosition(pPosY)
		lua_subYPosition(obj.pointer,pPosY)
	end
	
	-- Função para subtrair um valor a posição xy do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	31/03/2009
	-- @final	31/03/2009
	-- @param	double x, valor a subtrair no eixo x do objeto
	-- @param	double y, valor a subtrair no eixo y do objeto
	local function subPosition(pPosX,pPosY)
		lua_subPosition(obj.pointer,pPosX,pPosY)
	end
	
	-- Função para setar o espelhamento do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @param	int mirroring, espelhamento,
	local function setMirroring(pMirroring)
		lua_setMirroring(obj.pointer,pMirroring)
	end
	
	-- Função para retornar o espelhamento do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	11/03/2009
	-- @final	12/03/2009
	-- @return	int
	local function getMirroring()
		return lua_getMirroring(obj.pointer)
	end

	obj.changeAnimationByIndex	= changeAnimationByIndex
	obj.changeAnimation			= changeAnimation
	obj.animationIsPlaying		= animationIsPlaying
	obj.getAnimationOn			= getAnimationOn
	obj.getFrameOn				= getFrameOn
	obj.getXPosition			= getXPosition
	obj.getYPosition			= getYPosition
	obj.getPosition				= getPosition
	obj.setXPosition			= setXPosition
	obj.setYPosition			= setYPosition
	obj.setPosition				= setPosition
	obj.addXPosition			= addXPosition
	obj.addYPosition			= addYPosition
	obj.addPosition				= addPosition
	obj.subXPosition			= subXPosition
	obj.subYPosition			= subYPosition
	obj.subPosition				= subPosition
	obj.setMirroring			= setMirroring
	obj.getMirroring			= getMirroring
	
	return obj
end

