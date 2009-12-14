--[[
	-- Funcão
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @param	int pPointer, endereco na memoria da classe do layer
-]]
function setPointer(pPointer)
	this.pointer = pPointer
end
--[[
	-- Funcão que retorna o numero de tiles do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	int
-]]
function script_getTileNumber()
	return #this.tiles;
end
--[[
	-- Funcão que retorna a animacao de um tile
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	int
-]]
function script_getTileAnimation(pTile)
	return this.tiles[pTile].animation;
end
--[[
	-- Funcão que retorna as instancias de um tile
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	{}{x,y}
-]]
function script_getTileInstances(pTile)
	return #this.tiles[pTile].position;
end
--[[
	-- Funcão que retorna a posicao x de uma instancia de um tile
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @param	int pTile, indice do tile
	-- @param	int pInst, instancia do tile
	-- @return	int
-]]
function script_getTileXPosition(pTile,pInst)
	return this.tiles[pTile].position[pInst].x;
end
--[[
	-- Funcão que retorna a posicao y de uma instancia de um tile
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @param	int pTile, indice do tile
	-- @param	int pInst, instancia do tile
	-- @return	int
-]]
function script_getTileYPosition(pTile,pInst)
	return this.tiles[pTile].position[pInst].y;
end
--[[
	-- Funcão que retorna o nome do pacote de sprites do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	string
-]]
function script_getSpritePack()
	return this.sprite
end
--[[
	-- Funcão que retorna o nome do pacote de animacoes do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	string
-]]
function script_getAnimationPack()
	return this.animation
end
--[[
	-- Funcão que retorna a velocidade de scrooling do eixo x
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	double
-]]
function script_getXScroolingSpeed()
	return this.xScroolingSpeed
end
--[[
	-- Funcão que retorna a velocidade de scrooling do eixo y
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
	-- @return	double
-]]
function script_getYScroolingSpeed()
	return this.yScroolingSpeed
end
--[[
	-- Funcão que executa a lógica de um script
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
-]]
function script_logic()
	this.logic();
end

--[[
	-- Classe que representa um layer de um Cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	14/12/2009
-]]
function Layer()
	local obj = {}

	--[[
		-- Metodo para setar o ponteiro da classe
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pPointer, endereco na memoria da classe
	-]]
	local function setPointer(pPointer)
		obj.pointer = pPointer
	end
	--[[
		--Função que retorna o número de tiles do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	18/03/2009
		-- @return	int
	-]]
	local function getTileNumber()
		return lua_getTileNumber(obj.pointer);
	end
	--[[
		-- Função que retorna a animação de um tile do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	13/12/2009
		-- @return	int
	-]]
	local function getTileAnimation(pTile)
		return lua_getTileAnimation(obj.pointer,pTile);
	end
	--[[
		-- Funcão que muda a animacao do tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pTile, numero do tile a mudar a animacao
		-- @param	int pAnimation, numero da nova animacao
	-]]
	local function setTileAnimation(pTile,pAnimation)
		lua_setTileAnimation(
			obj.pointer,
			pTile - 1,
			pAnimation
		);
	end
	--[[
		--Função que retorna o número de instâncias de um tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	18/03/2009
		-- @param	int pTile, indice do tile
		-- @return	int
	-]]
	local function getTileInstances(pTile)
		local inst = lua_getTileInstances(obj.pointer,pTile);
		for i = 1, #inst do
			inst[i].x = inst[i][1];
			inst[i].y = inst[i][2];
		end
		return inst;
	end
	--[[
		-- Funcao que adiciona uma instancia a um determinado tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pTile, indice do tile
		-- @param	{x,y} pPos, posicão x,y do novo tile
	-]]
	local function addTileInstance(pTile,pPos)
		lua_addTileInstance(
			obj.pointer,
			pTile - 1,
			pPos.x,
			pPos.y
		);	
	end
	--[[
		-- Funcao que remove uma instancia de um determinado tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pTile, indice do tile
		-- @param	int pInst, indice da instancia do tile a ser removida
	-]]
	local function removeTileInstance(pTile,pInst)
		lua_removeTileInstance(
			obj.pointer,
			pTile - 1,
			pInst - 1
		);	
	end
	--[[
		-- Funcão que retorna a posicão de uma determinada instancia de um determinado tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pTile, indice do tile
		-- @param	int pInst, instancia do tile
		-- @return	{x,y}
	-]]
	local function getTilePosition(pTile,pInst)
		X,Y = lua_getTilePosition(
		obj.pointer,
		pTile - 1,
		pInst - 1
		);
		return { x = X, y = Y}
	end
	--[[
		-- Funcao para setar a posicao de uma instancia de um tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	13/12/2009
		-- @param	int pTile	, indice do tile
		-- @param	int pInst	, instancia do tile
		-- @param	int pPos	, nova posicao para o tile
	-]]
	local function setTilePosition(pTile,pInst,pPos)
		lua_setTilePosition(
			obj.pointer,
			pTile - 1,
			pInst - 1,
			pPos.x,
			pPos.y
		);	
	end
--[[
	--Função que retorna o número de objects do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	-- @return	int
	local function getObjectNumber()
		return #objects;
	end

	--Função que retorna o script de um object do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	-- @return	int
	local function getObjectScript(object)
		return objects[object].script;
	end

	--Função que retorna o número de instâncias de um object
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	-- @return	int
	local function getObjectInstances(object)
		return #objects[object].position;
	end

	--Função que retorna a posição x de uma determinada instância de um determinado object
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	-- @param	int object, índice do object
	-- @param	int inst, instância do object
	-- @return	int
	local function getObjectXPosition(object,inst)
		return objects[object].position[inst].x;	
	end

	--Função que retorna a posição y de uma determinada instância de um determinado object
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	-- @param	int object, índice do object
	-- @param	int inst, instância do object
	-- @return	int
	local function getObjectYPosition(object,inst)
		return objects[object].position[inst].y;
	end
-]]
	--Função que executa a lógica do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	local function logic()
		--put your logic here
	end

	obj.setPointer				= setPointer
	obj.script_getTileNumber	= script_getTileNumbe
	obj.script_getTileAnimation	= script_getTileAnimation
	obj.script_getTileInstances	= script_getTileInstances
	obj.script_getTileXPosition	= script_getTileXPosition
	obj.script_getTileYPosition	= script_getTileYPosition
	obj.getTileNumber			= getTileNumber
	obj.getTileAnimation		= getTileAnimation
	obj.setTileAnimation		= setTileAnimation
	obj.getTileInstances		= getTileInstances
	obj.addTileInstance			= addTileInstance
	obj.removeTileInstance		= removeTileInstance
	obj.getTilePosition			= getTilePosition
	obj.setTilePosition			= setTilePosition
	obj.logic					= logic

	obj.pointer			= nil
	-- Localização do arquivo de sprites do layer
	obj.sprite			= ""
	--localização do arquivo de animações do layer
	obj.animation		= ""
	--velocidade de deslocamento horizontal do layer
	obj.xScroolingSpeed = 1.0
	--velocidade de deslocamento vertical do layer
	obj.yScroolingSpeed = 1.0
	--vetor com os tiles e suas posições no layer
	obj.tiles			= { }
	--vetor com os objetcs e suas posições no layer
	obj.objects			= { }
	return obj;
end

