--[[
	-- Classe que representa um tile de um layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	15/12/2009
-]]
function Tile(pPointer)
	local this = {}

	--[[
		-- Função que retorna a animação do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	13/12/2009
		-- @return	int
	-]]
	local function getAnimation()
		return lua_tile_getAnimation(this.mPointer);
	end
	--[[
		-- Funcão que muda a animacao do tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pAnimation, numero da nova animacao
	-]]
	local function setAnimation(pAnimation)
		lua_tile_setAnimation(this.mPointer,pAnimation);
	end

	--[[
		-- Funcão que clona o tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	14/12/2009
		-- @version	15/12/2009
		-- @param	{x,y} pPosition, posicão do tile clonado
	-]]
	local function clone(pPosition)
		lua_tile_clone(this.mPointer,pPosition.x,pPosition.y)
	end

	--[[
		-- Funcão que retorna a posicão do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	15/12/2009
		-- @return	{x,y}
	-]]
	local function getPosition()
		X,Y = lua_tile_getPosition(this.mPointer);
		return { x = X, y = Y}
	end
	--[[
		-- Funcao para setar a posicao do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	15/12/2009
		-- @param	{x,y} pPosition	, nova posicao para o tile
	-]]
	local function setPosition(pPosition)
		lua_tile_setPosition(
			this.mPointer,
			pPosition.x,
			pPosition.y
		);
	end
	--[[
		-- Funcao para retornar o layer do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	15/12/2009
		-- @return	Layer
	-]]
	local function getLayer()
		local layer = Layer()
		layer.setPointer(lua_tile_getLayerPointer(this.mPointer))
		return layer
	end

	this.getAnimation	= getAnimation
	this.setAnimation	= setAnimation
	this.clone			= clone
	this.getPosition	= getPosition
	this.setPosition	= setPosition
	this.getLayer		= getLayer

	--ponteiro para a classe
	this.mPointer		= pPointer

	return this
end

