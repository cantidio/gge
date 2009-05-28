--Arquivo de script de objetos com diretivas básicas
Mirroring = {
	Normal	= 0,
	HFlip	= 1,
	VFlip	= 2,
	VHflip	= 3,
	HVFlip	= 3
}
-- endereco de memória do objeto que invocou o script
objectPointer	= nil
-- nome do script
name			= ""
-- localização do arquivo de sprites do objeto
sprite			= ""
-- localização do arquivo de animação do objeto
animation		= ""
-- localização do arquivo de colisões do objeto
colision		= ""
-- localização do arquivo de paleta do objeto
palette			= ""
-- impulso horizontal do objeto
xPulse			= 1
-- impulso horizontal máximo atingido pelo objeto
xPulseMax		= 2
-- impulso vertical do objeto
yPulse			= 0
-- Se o objeto é afetado pela gravidade do cenário em que está inserido
gravityAffected	= false
-- Se o objeto pode colidir com outros
colisional		= false
-- estado do objeto
state			= 0

-- Função para registrar o ponteiro do objeto que invocou o script
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int pointer, posição do objeto na memória
function getObject(pointer)
	objectPointer=pointer
end

-- Função para mudar a animação do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int x, nova animação a trocar
function changeAnimation(x)
	lua_changeAnimation(objectPointer,x)
end

-- Função que retorna verdadeiro se a animação atual ainda está tocando
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @return	bool
function animationIsPlaying()
	return lua_animationIsPlaying(objectPointer)
end

-- Função que retorna o número da animação que está tocando
--
-- @author	Cantidio Oliveira Fontes
-- @since	14/03/2009
-- @final	14/03/2009
-- @return	int
function getAnimationOn()
	return lua_getAnimationOn(objectPointer)
end

-- Função que retorna o número do frame atual da animação que está tocando
--
-- @author	Cantidio Oliveira Fontes
-- @since	14/03/2009
-- @final	14/03/2009
-- @return	int
function getFrameOn()
	return lua_getFrameOn(objectPointer)
end	
	
-- Função para retornar a posiçãoX do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @return	int
function getXPosition()
	return lua_getXPosition(objectPointer)
end

-- Função para retornar a posiçãoY do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @return	int
function getYPosition()
	return lua_getYPosition(objectPointer)
end

-- Função para retornar a posição do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	31/03/2009
-- @final	31/03/2009
-- @return	table
function getPosition()
	return {x=getXPosition(),y=getYPosition()}
end

-- Função para setar a posiçãoX do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int x, posição x do objeto
function setXPosition(x)
	lua_setXPosition(objectPointer,x)
end

-- Função para setar a posiçãoY do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int y, posição y do objeto
function setYPosition(y)
	lua_setYPosition(objectPointer,y)
end

-- Função para setar a posição do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int x, posição x do objeto
-- @param	int y, posição y do objeto
function setPosition(x,y)
	lua_setPosition(objectPointer,x,y)
end

-- Função para adicionar um valor a posição x do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int x, valor a adicionar no eixo x do objeto
function addXPosition(x)
	lua_addXPosition(objectPointer,x)
end

-- Função para adicionar um valor a posição y do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int y, valor a adicionar no exito y do objeto
function addYPosition(y)
	lua_addYPosition(objectPointer,y)
end

-- Função para adicionar um valor a posição xy do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int x, valor a adicionar no eixo x do objeto
-- @param	int y, valor a adicionar no eixo y do objeto
function addPosition(x,y)
	lua_addPosition(objectPointer,x,y)
end

-- Função para subtrair um valor a posição x do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	31/03/2009
-- @final	31/03/2009
-- @param	double x, valor a subtrair no eixo x do objeto
function subXPosition(x)
	lua_subXPosition(objectPointer,x)
end

-- Função para subtrair um valor a posição y do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	31/03/2009
-- @final	31/03/2009
-- @param	double y, valor a subtrair no exito y do objeto
function subYPosition(y)
	lua_subYPosition(objectPointer,y)
end

-- Função para subtrair um valor a posição xy do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	31/03/2009
-- @final	31/03/2009
-- @param	double x, valor a subtrair no eixo x do objeto
-- @param	double y, valor a subtrair no eixo y do objeto
function subPosition(x,y)
	lua_subPosition(objectPointer,x,y)
end

-- Função para setar o espelhamento do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @param	int mirroring, espelhamento,
function setMirroring(mirroring)
	lua_setMirroring(objectPointer,mirroring)
end

-- Função para retornar o espelhamento do objeto
--
-- @author	Cantidio Oliveira Fontes
-- @since	11/03/2009
-- @final	12/03/2009
-- @return	int
function getMirroring()
	return lua_getMirroring(objectPointer)
end

