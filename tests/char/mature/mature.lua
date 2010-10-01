function Mature(pLayer)
	GGE_game_log("Mature()")
	local this = { }
	this = GGE_Player(
		"tests/char/mature/mature.gspk",
		"tests/char/mature/mature.gapk",
		pLayer
	)
		
	this.stateBorning = function()
		print("mature state: borning")
		--this.setAfterImageMethodTrans(0.5)
		--this.setAfterImageMethodAdd({r=200,g=0,b=0},{r=0,g=0,b=0},0.5)
		
		this.state = this.stateStandInit
	end

	this.stateStandInit = function()
		print("mature state: stand")
		this.changeAnimation(0,0)
		this.state = this.stateStanding
	end

	this.stateStanding = function()
		if this.mInput.button1() then
			this.state = this.stateKick1Init
		elseif this.mInput.button2() then
			this.state = this.stateKick2Init
		end
	end

	this.stateKick1Init = function()
		print("mature state: kick1")
		--this.setAfterImageMode(true,2,10)
		this.changeAnimation(10,0)
		this.state = this.stateKicking1
	end

	this.stateKicking1 = function()
		this.addPosition({x=-5,y=0})
		if not this.animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			this.state = this.stateStandInit
		end
	end

	this.stateKick2Init = function()
		print("mature state: kick2")
		--this.getBackground().getlayer)(.getBac
		--this.setAfterImageMode(true,2,10)
		this.changeAnimation(10,1)
		this.state = this.stateKicking2
	end

	this.stateKicking2 = function()
		if not this.animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			this.state = this.stateStandInit
		end
	end

	this.logic = function()
		this.basicLogic()
		if this.mInput.buttonDown()  then
			this.addPosition({x=0,y=3})
		elseif this.mInput.buttonUp() then
			this.subPosition({x=0,y=3})
		end
		
		if this.mInput.buttonRight() then
			this.addPosition({x=3,y=0})
		elseif this.mInput.buttonLeft() then
			this.subPosition({x=3,y=0})
		end

		this.state()
	end
	
	this.state				= this.stateBorning

	return this
end

