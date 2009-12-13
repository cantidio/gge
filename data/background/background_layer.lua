-- Arquivo com as função e declarações de variáveis básicas
-- Localização do arquivo de sprites do layer
sprite			= ""
--localização do arquivo de animações do layer
animation		= ""
--velocidade de deslocamento horizontal do layer
xScroolingSpeed = 1.0
--velocidade de deslocamento vertical do layer
yScroolingSpeed = 1.0
--vetor com os tiles e suas posições no layer
tiles			= { }
--vetor com os objetcs e suas posições no layer
objects			= { }
--Memory Address for the layer class that called the script
layerPointer	= nil

--[[
	-- Função para registrar o ponteiro do layer que invocou o script
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	20/03/2009
	-- @param	int pPointer, endereço do layer na memória
-]]
function setLayerPointer(pPointer)
	layerPointer = pPointer
end

function script_getTileNumber()
	return #tiles;
end

function script_getTileAnimation(pTile)
	return tiles[pTile].animation;
end

function script_getTileInstances(pTile)
	return #tiles[pTile].position;
end

function script_getTileXPosition(pTile,pInst)
	return tiles[pTile].position[pInst].x;
end

function script_getTileYPosition(pTile,pInst)
	return tiles[pTile].position[pInst].y;
end

--Função que retorna o número de objects do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
-- @return	int
function script_getObjectNumber()
	return #objects;
end

--Função que retorna o script de um object do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
-- @return	int
function script_getObjectScript(object)
	return objectss[object].script;
end

--Função que retorna o número de instâncias de um object
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
-- @return	int
function script_getObjectInstances(object)
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
function script_getObjectXPosition(object,inst)
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
function script_getObjectYPosition(object,inst)
	return objects[object].position[inst].y;
end

-----------------------------------------------------------------------
--[[
	--Função que retorna o número de tiles do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	18/03/2009
	-- @return	int
-]]
function getTileNumber()
	return lua_getTileNumber(layerPointer);
end
--[[
	-- Função que retorna a animação de um tile do layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	18/03/2009
	-- @version	13/12/2009
	-- @return	int
-]]
function getTileAnimation(pTile)
	return lua_getTileAnimation(layerPointer,pTile);
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
function setTileAnimation(pTile,pAnimation)
	lua_setTileAnimation(layerPointer,pTile - 1,pAnimation);
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
function getTileInstances(pTile)
	local inst = lua_getTileInstances(layerPointer,pTile);
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
function addTileInstance(pTile,pPos)
	lua_addTileInstance(
		layerPointer,
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
function removeTileInstance(pTile,pInst)
	lua_removeTileInstance(
		layerPointer,
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
function getTilePosition(pTile,pInst)
	X,Y = lua_getTilePosition(layerPointer,pTile-1,pInst-1);
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
function setTilePosition(pTile,pInst,pPos)
	lua_setTilePosition(
		layerPointer,
		pTile - 1,
		pInst - 1,
		pPos.x,
		pPos.y
	);	
end

--Função que retorna o número de objects do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
-- @return	int
function getObjectNumber()
	return #objects;
end

--Função que retorna o script de um object do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
-- @return	int
function getObjectScript(object)
	return objectss[object].script;
end

--Função que retorna o número de instâncias de um object
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
-- @return	int
function getObjectInstances(object)
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
function getObjectXPosition(object,inst)
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
function getObjectYPosition(object,inst)
	return objects[object].position[inst].y;
end

--Função que executa a lógica do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @version	18/03/2009
function logic()
	--put your logic here
end

