#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359f
#define E 2.71828f

uniform vec2 iResolution;
uniform float iTime;

void main(void) {
		vec2 xy = (gl_FragCoord.xy - 0.5f * iResolution) / length(0.5f * iResolution);
		vec3 col = vec3(0.f, 0.f, 0.f);

		const float scale = 0.1f;

		float tr1 = 0.05f * scale;
		float tr2 = 0.2f * scale;
		float tr3 = 0.25f * scale;
		float tr4 = 0.27f * scale;

		// tr1 *= (0.6f + 0.09f * cos(iTime * PI));
		// tr2 *= (0.6f + 0.09f * cos(iTime * PI));
		// tr3 *= (0.6f + 0.09f * cos(iTime * PI));
		// tr4 *= (0.6f + 0.09f * cos(iTime * PI));

		float r = length(xy);
		float rho = asin(abs(xy.y / r));

		if (xy.x >= 0 && xy.y < 0)
		{
			rho = PI * 2.0f - rho;
		}
		else if (xy.x <= 0)
		{
			if (xy.y >= 0)
			{
				rho = PI - rho;
			}
			else if (xy.y <= 0)
			{
				rho += 1.0f * PI;
			}
		}

		// Forth option
		float acceptL = 2.f * (iTime - 10.0f * r);

		
		// First option
		//float acceptL = 2.f * pow(iTime, 1.0f);
		float acceptR = acceptL + PI / 180.f * 90.0f + 0.2f;

		float offAceptL = floor(acceptL / abs(2.0f * PI));
		float offAceptR = floor(acceptR / abs(2.0f * PI));

		acceptL -= (offAceptL) * 2.0f * PI;
		acceptR -= (offAceptR) * 2.0f * PI;

		// Forth option
		acceptL *= pow(r * 10.0f, acceptL);
		acceptR *= mix(pow(r * 2.0f, acceptR / r), acceptR, PI);

		// First option
		//acceptR *= mix(pow(acceptL, r), acceptR, PI);

		if (r > tr1 && r < tr2)
		{
			if ((acceptR < acceptL && (rho >= acceptL || rho <= acceptR)) ||(rho >= acceptL && rho <= acceptR))
			{
				col = vec3(0.8f, 0.8f, 7.0f);
			}

			col.xyz *= smoothstep(tr2, tr1, r);
			col.y *= 0.4f + 0.6f * abs(cos(rho * iTime));
			col.z *= 0.4f + 0.2f * abs(sin(rho * iTime));
			gl_FragColor = vec4(col, 1.0f);
		}
		else if (r >= tr3 && r <= tr4)
		{
			
			if ((acceptR < acceptL && (rho >= acceptL || rho <= acceptR)) ||(rho >= acceptL && rho <= acceptR))
			{
				col = vec3(0.8f, 0.8f, 7.0f);
				col.y *= 0.5f + 0.6f * abs(cos(rho * iTime));
				col.z *= 0.4f + 0.2f * abs(sin(rho * iTime));
			}
			else
			{
				col = vec3(1.0f, 1.0f, 1.0f);
			}
			col.xyz *= smoothstep(tr4, tr3, r);
			gl_FragColor = vec4(col, 1.0f);
		}
}