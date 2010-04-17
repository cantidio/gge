function Mature(pPointer)
	local this = { }
	this = Player(pPointer)
	
	local function persistentFunction()
	end

	local function stateBorning()
		print("mature state: borning")
		this.setAfterImageMethodTrans(0.5)
		--this.setAfterImageMethodAdd({r=200,g=0,b=0},{r=0,g=0,b=0},0.5)
		
		this.state = this.stateStandInit
	end

	local function stateStandInit()
		print("mature state: stand")
		this.changeAnimationByIndex(1)
		this.state = this.stateStanding
	end

	local function stateStanding()
		if this.mInput.button1() then
			print("mature state: stand")
			this.state = this.stateKick1Init
		elseif this.mInput.button2() then
			this.state = this.stateKick2Init
		end
	end

	local function stateKick1Init()
		print("mature state: kick1")
		this.setAfterImageMode(true,2,10)
		this.changeAnimation(10,0)
		this.state = this.stateKicking1
	end

	local function stateKicking1()
		if not this.animationIsPlaying() then
			this.setAfterImageMode(false,1,1)
			this.state = this.stateStandInit
		end
	end

	local function stateKick2Init()
		print("mature state: kick2")
		this.getBackground().getlayer)(.getBac
		this.setAfterImageMode(true,2,10)
		this.changeAnimation(10,1)
		this.state = this.stateKicking2
	end

	function stateKicking2()
		if not this.animationIsPlaying() then
			this.setAfterImageMode(false,1,1)
			this.state = this.stateStandInit
		end
	end

	local function logic()
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
	
	this.name				= "Mature"
	this.spritePack			= "data/character/player/mature/mature.gspk"
	this.animationPack		= "data/character/player/mature/mature.gapk"
	this.life				= 1000
	this.imortalTime		= 0
	this.helperMaxInstances	= { }
	this.helperScriptFile	= { }
	this.logic				= logic
	this.state				= stateBorning
	
	
	this.stateStandInit		= stateStandInit
	this.stateStanding		= stateStanding
	this.stateKick2Init		= stateKick2Init
	this.stateKicking2		= stateKicking2
	this.stateKick1Init		= stateKick1Init
	this.stateKicking1		= stateKicking1
	return this
end
this = Mature()

