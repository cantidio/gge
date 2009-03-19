-- arquivo com as função e declarações de variáveis básicas
--localização do arquivo de sprites do layer
sprite			= ""
--localização do arquivo de animações do layer
animation		= ""
--velocidade de deslocamento horizontal do layer
xScroolingSpeed = 1.0
--velocidade de deslocamento vertical do layer
yScroolingSpeed = 1.0
--vetor com os tiles e suas posições no layer
tiles			= {}
--vetor com os objetcs e suas posições no layer
objects			= {}

--Função que retorna o número de tiles do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @return	int
function getTileNumber()
	return #tiles;
end
--Função que retorna a animação de um tile do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @return	int
function getTileAnimation(tile)
	return tiles[tile].animation;
end

--Função que retorna o número de instâncias de um tile
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @return	int
function getTileInstances(tile)
	return #tiles[tile].position;
end
--Função que retorna a posição de uma determinada instância de um determinado tile
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @param	int tile, índice do tile
-- @param	int inst, instância do tile
-- @return	int
-- @return	int
function getTilePosition(tile,inst)
	return tiles[tile].position[inst].x;
	return tiles[tile].position[inst].y;
end
--Função que retorna o número de objects do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @return	int
function getObjectNumber()
	return #objects;
end
--Função que retorna o script de um object do layer
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @return	int
function getObjectScript(object)
	return objectss[object].script;
end

--Função que retorna o número de instâncias de um object
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @return	int
function getObjectInstances(object)
	return #objects[object].position;
end
--Função que retorna a posição de uma determinada instância de um determinado object
--
-- @author	Cantidio Oliveira Fontes
-- @since	18/03/2009
-- @final	18/03/2009
-- @param	int object, índice do object
-- @param	int inst, instância do object
-- @return	int
-- @return	int
function getObjectPosition(object,inst)
	return objects[object].position[inst].x;
	return objects[object].position[inst].y;
end

