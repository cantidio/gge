--[[
	-- Classe para representar os inputs
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	26/01/2010
-]]
function Input()
	this = {}
	--[[
		-- Método para verificar se o botão start está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function buttonStart()
		return lua_input_buttonStart()
	end
	--[[
		-- Método para verificar se o botão cima está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function buttonUp()
		return lua_input_buttonUp()
	end
	--[[
		-- Método para verificar se o botão baixo está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function buttonDown()
		return lua_input_buttonDown()
	end
	--[[
		-- Método para verificar se o botão esquerda está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function buttonLeft()
		return lua_input_buttonLeft()
	end
	--[[
		-- Método para verificar se o botão direita está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function buttonRight()
		return lua_input_buttonRight()
	end
	--[[
		-- Método para verificar se o botão1 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button1()
		return lua_input_button1()
	end
	--[[
		-- Método para verificar se o botão2 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button2()
		return lua_input_button2()
	end
	--[[
		-- Método para verificar se o botão3 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button3()
		return lua_input_button3()
	end
	--[[
		-- Método para verificar se o botão4 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button4()
		return lua_input_button4()
	end
	--[[
		-- Método para verificar se o botão5 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button5()
		return lua_input_button5()
	end
	--[[
		-- Método para verificar se o botão6 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button6()
		return lua_input_button6()
	end
	--[[
		-- Método para verificar se o botão7 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button7()
		return lua_input_button7()
	end
	--[[
		-- Método para verificar se o botão8 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function button8()
		return lua_input_button8()
	end
	
	this.buttonStart	= buttonStart
	this.buttonUp		= buttonUp
	this.buttonDown		= buttonDown
	this.buttonLeft		= buttonLeft
	this.buttonRight	= buttonRight
	this.button1		= button1
	this.button2		= button2
	this.button3		= button3
	this.button4		= button4
	this.button5		= button5
	this.button6		= button6
	this.button7		= button7
	this.button8		= button8

	return this
end

