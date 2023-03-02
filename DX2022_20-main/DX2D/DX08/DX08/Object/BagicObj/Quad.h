#pragma once
class Quad
{
public:
	Quad();
	Quad(wstring file);
	Quad(wstring file, Vector2 size);
	~Quad();

	virtual void Update();
	virtual void Render();
	void SetRender();

	virtual void CreateMaterial(wstring file);
	virtual void CreateMesh();

	void SetVS(shared_ptr<VertexShader> shader) { _vs = shader; }
	void SetPS(shared_ptr<PixelShader> shader) { _ps = shader; }

	shared_ptr<Transform> GetTransform() { return _transform; }

	Vector2 GetImageSize() { return _size; }

protected:
	Vector2 _size;

	// Mesh
	vector<UINT> _indices;
	vector<Vertex> _vertices;

	shared_ptr<VertexBuffer>	 _vertexBuffer;
	shared_ptr<IndexBuffer>		 _indexBuffer;

	// Material
	shared_ptr<VertexShader>	 _vs;
	shared_ptr<PixelShader>		 _ps;
	shared_ptr<SRV>				 _srv;

	// ������Ʈ ���� : ��ǰ ����
	// -> ���뼺 ����
	// -> ������
	// => ��ǥ���� ����Ƽ�� ����
	shared_ptr<Transform> _transform;
};
