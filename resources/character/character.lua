--Arquivo de script de personagens com diretivas básicas

-- life do personagem
life				= 0
-- poder de ataque do personagem
attackPower			= 0
-- poder de defesa do personagem
defensePower		= 0
-- tempo que o personagem fica imortal depois de atingido
imortalTime			= 0
-- O número máximo de instancias de um helper
helperMaxInstances	= 0
-- Arquivo de script do helper
helperScriptFile	= ""

-- Função para retornar o life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function getLife()
	return lua_getLife(objectPointer)
end

-- Função para setar o life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int life, life do personagem
function setLife(life)
	return lua_setLife(objectPointer,life)
end

-- Função para retirar um valor do life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int life, life a ser subtraído
function subLife(life)
	return lua_subLife(objectPointer,life)
end

-- Função para adicionar um valor ao life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int life, life a ser adicionado
function addLife(life)
	return lua_addLife(objectPointer,life)
end

-- Função que retorna verdadeiro se o personagem está vivo
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function isAlive()
	return lua_isAlive(objectPointer)
end

-- Função que ativa o personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function ativate()
	lua_ativate(objectPointer)
end

-- Função que ativa o personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function inativate()
	lua_inativate(objectPointer)
end

-- Função que retorna verdadeiro se o personagem está ativo
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function isAtive()
	return lua_isAtive(objectPointer)
end

-- Função que retorna verdadeiro se o personagem está imortal
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function isImortal()
	return lua_isImortal(objectPointer)
end

-- Função que machuca o personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function hurt(damage)
	return lua_hurt(objectPointer,damage)
end

-- Função que chama um helper do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function callHelper(x,y,mirroring)
	lua_callHelper(objectPointer,x,y,mirroring)
end


