function Mammon(pPointer)
	local this = { }
	this = Player(pPointer)
	
	local function persistentFunction()
	end

	local function stateBorning()
		this.setAfterImageMethodTrans(0.5)
		this.setAfterImageMode(true,5,10)
		--this.setAfterImageMethodAdd({blue=200},{},0.5)
		this.state = this.stateStandInit
		this.setMirroring(Mirroring.HFlip)
	end

	local function stateStandInit()
		this.changeAnimationByIndex(1)
		this.state = this.stateStanding
	end

	local function stateStanding()
		if this.mInput.button1() then
			print("state: stand")
			this.state = this.stateAttackInit
		elseif this.mInput.buttonDown() then
			this.state= this.stateAInit
		elseif this.mInput.buttonRight() or this.mInput.buttonLeft() then
			this.state = this.stateWalkInit
		end
	end

	local function stateAInit()
		this.changeAnimationByIndex(2)
		this.state = this.stateAing
	end
	
	local function stateAing()
		if not this.mInput.buttonDown() then
			this.state = stateStandInit
		end
	end
	
	local function stateWalkInit()
		this.changeAnimationByIndex(8);
		this.state = this.stateWalking
	end
	
	local function stateWalking()
		if this.mInput.button1() then
			this.state = this.stateAttackInit
			
		elseif this.mInput.buttonDown() then
			this.state= this.stateAInit
			
		elseif this.mInput.buttonRight() then 
			this.addPosition({x=5})
		elseif this.mInput.buttonLeft() then
			this.subPosition({x=5})
		else
			this.state = stateStandInit
		end
	end
	
	local function stateAttackInit()
		print("state attack")
		--this.setAfterImageMode(true,30,5)
		this.changeAnimation(100,0)
		this.state = this.stateAttacking
	end

	local function stateAttacking()
		if not this.animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			this.state = this.stateStandInit
		end
	end

	local function logic()
		this.state()
	end
	
	this.name				= "Mammon"
	this.spritePack			= "tests/char/mammon/mammon.gspk"
	this.animationPack		= "tests/char/mammon/mammon.gapk"
	this.life				= 1000
	this.imortalTime		= 0
	this.helperMaxInstances	= { }
	this.helperScriptFile	= { }
	this.logic				= logic
	this.state				= stateBorning

	this.stateAInit			= stateAInit
	this.stateAing			= stateAing
	
	this.stateWalkInit		= stateWalkInit
	this.stateWalking		= stateWalking
	this.stateStandInit		= stateStandInit
	this.stateStanding		= stateStanding
	this.stateAttackInit	= stateAttackInit
	this.stateAttacking		= stateAttacking
	return this
end
this = Mammon()

