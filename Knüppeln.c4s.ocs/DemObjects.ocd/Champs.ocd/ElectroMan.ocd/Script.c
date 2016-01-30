/**
	FireMan
	

	@author 
*/


func LaunchSpecial1(object clonk, int x, int y)
{
	clonk->LaunchSpell(ElectroProjectile, x, y, 0, 0);
}

func LaunchSpecial2(object clonk, int x, int y)
{
	clonk->LaunchSpell(ElectroOrb, x, y, 0, 0);
}

func JumpEffect(object clonk, from, to)
{
	Sound("electric_shot", false, 30);

	for(var i = from; i < to; i+=5)
	{
		var r = 10;
		var x = clonk->GetX() + Cos(i, r);
		var y = clonk->GetY() + Sin(i, r);
		
		var angle = Angle(0,0,x,y);
		
		var trailparticles =
		{
			Size = PV_Linear(15,0),
			Rotation = angle
		};
	
		CreateParticle("BlueSpark", x, y, Cos(i, r), Sin(i, r), 10, trailparticles);
	}
}

func BlockEffect(object clonk, range)
{
	for(var i = 0; i < 360; i+=10)
	{
		var r = range;
		var x = clonk->GetX() + Cos(i, r);
		var y = clonk->GetY() + Sin(i, r);
		
		var angle = Angle(0,0,x,y) + 90;
		
		var trailparticles =
		{
			Size = PV_Linear(15,0),
			Rotation = angle
		};
	
		CreateParticle("BlueSpark", x, y, 0, 0, 10, trailparticles);
	}
	
}