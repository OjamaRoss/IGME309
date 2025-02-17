#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform bool Compliment = false;

out vec4 Fragment;

void main()
{


	

	if(!Compliment){

		
		Fragment = vec4(Color,1);

		if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0) {
		
			Fragment = vec4(SolidColor, 1);

		}
		return;
		
	} else {

		
		if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0){
		
			Fragment = vec4(vec3(1.0f, 1.0f, 1.0f) - SolidColor, 1);
			return;

		}
		
		Fragment = vec4(vec3(1.0f, 1.0f, 1.0f) - Color, 1);
		return;

	}

}
	
