//*****************************************************************************************//
//**                                                                                     **//
//**                               CoordTf                                               **//
//**                                                                                     **//
//*****************************************************************************************//

#ifndef Class_CoordTf_Header
#define Class_CoordTf_Header

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace CoordTf {

	struct MATRIX {
		union {
			struct {
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};

		MATRIX operator*(MATRIX mat);
	};

	struct VECTOR4 {
		float x;
		float y;
		float z;
		float w;

		void as(float x1, float y1, float z1, float w1) {
			x = x1;
			y = y1;
			z = z1;
			w = w1;
		}

		VECTOR4 operator+(VECTOR4 v4);
		VECTOR4 operator-(VECTOR4 v4);
		VECTOR4 operator=(VECTOR4 v4);
	};

	struct VECTOR3 {
		float x;
		float y;
		float z;

		void as(float x1, float y1, float z1) {
			x = x1;
			y = y1;
			z = z1;
		}

		VECTOR3 operator+(VECTOR3 v3);
		VECTOR3 operator-(VECTOR3 v3);
		VECTOR3 operator=(VECTOR3 v3);
	};

	struct VECTOR2 {
		float x;
		float y;

		void as(float x1, float y1) {
			x = x1;
			y = y1;
		}

		VECTOR2 operator+(VECTOR2 v2);
		VECTOR2 operator-(VECTOR2 v2);
		VECTOR2 operator=(VECTOR2 v2);
	};

	//sñú»
	void MatrixIdentity(MATRIX* mat);
	//gåk¬
	void MatrixScaling(MATRIX* mat, float sizex, float sizey, float sizez);
	//x²ñ]
	void MatrixRotationX(MATRIX* mat, float theta);
	//y²ñ]
	void MatrixRotationY(MATRIX* mat, float theta);
	//z²ñ]
	void MatrixRotationZ(MATRIX* mat, float theta);
	//½sÚ®
	void MatrixTranslation(MATRIX* mat, float movx, float movy, float movz);
	//sñ«µZ
	void MatrixAddition(MATRIX* mat, MATRIX* mat1, MATRIX* mat2);
	//sñ|¯Z
	void MatrixMultiply(MATRIX* mat, MATRIX* mat1, MATRIX* mat2);
	//]u
	void MatrixTranspose(MATRIX* mat);
	//§Ï·sñ 1:_ÊuxNg 2:_ÊuxNg 3:JãûüxNg
	void MatrixLookAtLH(MATRIX* mat, VECTOR3 pos, VECTOR3 dir, VECTOR3 up);
	//ËeÏ·sñ  JÌæp, AXyNgä, nearv[, farv[
	void MatrixPerspectiveFovLH(MATRIX* mat, float theta, float aspect, float Near, float Far);
	//xNg3, sñ|¯Z
	void VectorMatrixMultiply(VECTOR3* v, MATRIX* mat);
	//xNg|¯Z
	void VectorMultiply(VECTOR3* v, float f);
	//xNgèZ
	void VectorDivision(VECTOR3* v, float f);
	//xNg«µZ
	void VectorAddition(VECTOR3* out, VECTOR3* in1, VECTOR3* in2);
	//tsñ
	bool MatrixInverse(MATRIX* invm, MATRIX* m);
	//r[|[gÏ·sñ
	void MatrixViewPort(MATRIX* mat, int width, int height);
	//³K»
	void Normalize(float* x, float* y, float* z, float* w);
	//³K»
	void VectorNormalize(VECTOR3* out, VECTOR3* in);
	//OÏ
	void VectorCross(VECTOR3* out, VECTOR3* in1, VECTOR3* in2);
	//àÏ
	float VectorDot(VECTOR3* in1, VECTOR3* in2);
	//ü`âÔ
	void StraightLinear(MATRIX* out, MATRIX* start, MATRIX* end, float t);
	//ÚxNgvZ
	VECTOR3 CalcTangent(VECTOR3 pos0, VECTOR3 pos1, VECTOR3 pos2,
		VECTOR2 uv0, VECTOR2 uv1, VECTOR2 uv2, VECTOR3 normal);
}

#endif
