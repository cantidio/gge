print("include: Mammon.lua")
function Mammon(pLayer)
	local this = { }
	this = GGE_Player(
		"tests/char/mammon/mammon.gspk",
		"tests/char/mammon/mammon.gapk",
		pLayer
	)
	
	this.stateBorning = function()
		print("state: borning")
		--this.setAfterImageMethodTrans(0.5)
		--this.setAfterImageMode(true,5,10)
		--this.setAfterImageMethodAdd({blue=200},{},0.5)
		this.state = this.stateStandInit
		this.setMirroring(Mirroring.HFlip)
	end

	this.stateStandInit = function()
		this.changeAnimationByIndex(1)
		this.state = this.stateStanding
	end

	this.stateStanding = function()
		if this.mInput.button1() then
			print("state: stand")
			this.state = this.stateAttackInit
		elseif this.mInput.buttonDown() then
			this.state= this.stateAInit
		elseif this.mInput.buttonRight() or this.mInput.buttonLeft() then
			this.state = this.stateWalkInit
		end
	end

	this.stateAInit = function()
		this.changeAnimationByIndex(2)
		this.state = this.stateAing
	end
	
	this.stateAing = function()
		if not this.mInput.buttonDown() then
			this.state = this.stateStandInit
		end
	end
	
	this.stateWalkInit = function()
		print("state: walk")
		this.changeAnimationByIndex(8);
		this.state = this.stateWalking
	end
	
	this.stateWalking = function()
		print("state: walking")
		if this.mInput.button1() then
			this.state = this.stateAttackInit
			
		elseif this.mInput.buttonDown() then
			this.state = this.stateAInit
			
		elseif this.mInput.buttonRight() then 
			this.addPosition({x=5,y=0})
		elseif this.mInput.buttonLeft() then
			this.subPosition({x=5,y=0})
		else
			this.state = this.stateStandInit
		end
	end
	
	this.stateAttackInit = function()
		print("state attack")
		--this.setAfterImageMode(true,30,5)
		this.changeAnimation(100,0)
		this.state = this.stateAttacking
	end

	this.stateAttacking = function()
		if not this.animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			this.state = this.stateStandInit
		end
	end

	this.logic = function()
		this.basicLogic()
		this.state()
	end
	this.state = this.stateBorning	
	return this
end

