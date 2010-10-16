function make_tile(animation, x, y)
	desc = ""
	desc = desc .. "			{\n"
	desc = desc .. "				animation	= " .. animation .. ",\n"
	desc = desc .. "				position	= { x = " .. x .. ", y = " .. y .. " }\n"
	desc = desc .. "			},\n"
	return desc
end

function make_Layer_class(
	pName,
	pSpritePackName,
	pAnimationPackName,
	pTiles
)
	desc = ""
	desc = desc .. "function " .. pName .. "()\n"
	desc = desc .. "	local this	= GGE_Layer(\n"
	desc = desc .. "		\"" .. pSpritePackName .. "\",\n"
	desc = desc .. "		\"" .. pAnimationPackName .. "\"\n"
	desc = desc .. "	)\n"
	desc = desc .. "	this.loadTiles(\n"
	desc = desc .. "		{\n"
	desc = desc .. pTiles
	desc = desc .. "		}\n"
	desc = desc .. "	)--end load tiles\n\n"
	
	desc = desc .. "	this.logic	= function()\n"
	desc = desc .. "		this.basicLogic()\n"
	desc = desc .. "		--put your layer logic here\n"
	desc = desc .. "	end\n\n"
	
	desc = desc .. "	return this\n"
	desc = desc .. "end\n"
	return desc
end

function make_BG_class(
	pName,
	pWidth,
	pHeight,
	pLayerNumber
)
	desc = ""
	desc = desc .. "function " .. pName .. "()\n"
	desc = desc .. "	local this	= GGE_Background()\n"
	desc = desc .. "	this.width	= " .. pWidth .. "\n"
	desc = desc .. "	this.height	= " .. pHeight .. "\n"
	
	--gera os layers
	for iterator = 1, pLayerNumber, 1 do
		desc = desc .. "	this.addLayer(" .. pName .. "_layer_" .. iterator .. "())\n"
	end	
	
	desc = desc .. "\n	this.logic	= function()\n"
	desc = desc .. "		this.basicLogic()\n"
	desc = desc .. "		--put your background logic here\n"
	desc = desc .. "	end\n\n"
	desc = desc .. "	return this\n"
	desc = desc .. "end\n"
	return desc
end

