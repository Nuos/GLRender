#pragma once
#include "fwd.h"
#include "TextureBuffer.h"
#include <vector>

namespace graphics
{
	class TextureData
	{
	public:
		~TextureData() { }

		virtual size_t size() const = 0;
		virtual void resize(size_t size) = 0;
		virtual GLvoid* dataPtr() const = 0;
	};


	template<class DATATYPE>
	class TypedTextureData : public TextureData
	{
	public:
		typedef DATATYPE DataType;
		typedef std::vector<DataType> Data;
		~TypedTextureData() { }

		inline DATATYPE get(size_t index)
		{
			return m_data[index];
		}

		inline void set(size_t index, DATATYPE value)
		{
			m_data[index] = value;
		}

		virtual size_t size() const
		{
			return m_data.size();
		}

		virtual void resize(size_t size)
		{
			m_data.resize(size, DATATYPE(0));
		}

		virtual GLvoid* dataPtr() const
		{
			return (GLvoid*)&m_data.front();
		}

		Data& data()
		{
			return m_data;
		}

		const Data& data() const
		{
			return m_data;
		}

	private:
		Data m_data;
	};

	typedef TypedTextureData<uchar> UCharTextureData;
	typedef boost::shared_ptr<UCharTextureData> UCharTextureData_Ptr;
	typedef boost::shared_ptr<const UCharTextureData> UCharTextureData_Const_Ptr;
	typedef TypedTextureData<float> FloatTextureData;
	typedef boost::shared_ptr<FloatTextureData> FloatTextureData_Ptr;
	typedef boost::shared_ptr<const FloatTextureData> FloatTextureData_Const_Ptr;


	class Texture : public TextureBuffer
	{
	public:
		struct TextureType
		{
			enum Enum
			{
				kInvalid = 0,
				kColor = 1,
				kFloat = 2
			};
		};

		static std::string TexturePath(const std::string& textureName);

		Texture();
		Texture(const std::string& filePath);
		Texture(int width, int height, int nChannels, const TextureType::Enum& textureType = TextureType::kColor);
		virtual ~Texture();

		void load(const std::string& filePath);

		const TextureType::Enum& textureType() const;

		TextureData_Ptr textureData();
		TextureData_Const_Ptr textureData() const;

		virtual int nChannels() const;
		virtual int width() const;
		virtual int height() const;
		virtual GLvoid* data() const;

		virtual GLenum type() const;

	private:
		void resetData();

		int m_width;
		int m_height;
		int m_nChannels;
		TextureType::Enum m_textureType;

		TextureData_Ptr m_data;
	};
}