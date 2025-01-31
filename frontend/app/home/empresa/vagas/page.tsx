"use client";

import { useState, useEffect } from "react";
import axios from "axios";
import Header from "@/components/Header";

interface Vaga {
  id: number;
  titulo: string;
  descricao: string;
  nome_empresa: string;
  data_abertura: string;
  salario: number;
  empresa: string;
}

export default function VagasPage() {
  const [vagas, setVagas] = useState<Vaga[]>([]);
  const [modalOpen, setModalOpen] = useState(false);
  const [editingVaga, setEditingVaga] = useState<Vaga | null>(null);
  const [formData, setFormData] = useState<Omit<Vaga, "id">>({
    titulo: "",
    descricao: "",
    nome_empresa: "",
    data_abertura: "",
    salario: 0,
    empresa: "",
  });

  useEffect(() => {
    axios
      .get("http://localhost:8080/vaga")
      .then((response) => setVagas(response.data))
      .catch((error) => console.error("Erro ao buscar vagas:", error));
  }, []);

  const handleDelete = async (id: number) => {
    try {
      await axios.delete(`http://localhost:8080/vaga/${id}`);
      setVagas(vagas.filter((vaga) => vaga.id !== id));
    } catch (error) {
      console.error("Erro ao deletar vaga:", error);
    }
  };

  const handleEdit = (vaga: Vaga) => {
    setEditingVaga(vaga);
    setFormData({ ...vaga });
    setModalOpen(true);
  };

  const handleAddVaga = () => {
    setEditingVaga(null);
    setFormData({
      titulo: "",
      descricao: "",
      nome_empresa: "",
      data_abertura: "",
      salario: 0,
      empresa: "",
    });
    setModalOpen(true);
  };

  const handleSubmit = async () => {
    try {
      if (editingVaga) {
        await axios.patch(`http://localhost:8080/vaga/${editingVaga.id}`, formData);
        setVagas(vagas.map((vaga) => (vaga.id === editingVaga.id ? { ...vaga, ...formData } : vaga)));
      } else {
        const response = await axios.post("http://localhost:8080/vaga", formData);
        setVagas([...vagas, response.data]);
      }
      setModalOpen(false);
    } catch (error) {
      console.error("Erro ao salvar vaga:", error);
    }
  };

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const { name, value } = e.target;
    setFormData((prev) => ({ ...prev, [name]: value }));
  };

  return (
    <div className="min-h-screen bg-[#f9fafb] text-black">
      <Header user="Empresa" />
      <div className="p-6 max-w-[1280px] mx-auto">
        <div className="flex items-center justify-between mb-8">
          <h2 className="text-4xl font-bold mb-4">Gerenciar Vagas</h2>
          <button
            className="bg-primary text-white py-3 px-6 rounded-lg text-lg font-semibold shadow-md hover:bg-red-800 mb-6"
            onClick={handleAddVaga}
          >
            Cadastrar Nova Vaga
          </button>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
          {vagas.length === 0 ? (
            <p className="text-center text-lg font-semibold">Nenhuma vaga encontrada</p>
          ) : (
            vagas.map((vaga) => (
              <div key={vaga.id} className="bg-white p-4 rounded-lg shadow-md">
                <h3 className="text-xl font-bold">{vaga.titulo}</h3>
                <p className="text-sm">{vaga.descricao}</p>
                <p className="text-green-600 font-bold">R$ {vaga.salario.toFixed(2)}</p>
                <p className="text-gray-500 text-sm">Empresa: {vaga.nome_empresa}</p>
                <p className="text-gray-400 text-xs">Aberta em: {vaga.data_abertura}</p>

                <div className="mt-4 flex justify-between">
                  <button
                    className="bg-yellow-500 text-white py-2 px-4 rounded-lg"
                    onClick={() => handleEdit(vaga)}
                  >
                    Editar
                  </button>
                  <button
                    className="bg-red-500 text-white py-2 px-4 rounded-lg"
                    onClick={() => handleDelete(vaga.id)}
                  >
                    Deletar
                  </button>
                </div>
              </div>
            ))
          )}
        </div>
      </div>

      {/* Modal */}
      {modalOpen && (
        <div className="fixed inset-0 bg-gray-500 bg-opacity-50 flex justify-center items-center z-50">
          <div className="bg-white p-8 rounded-lg shadow-lg max-w-[540px]">
            <h3 className="text-2xl font-bold mb-4">{editingVaga ? "Editar Vaga" : "Cadastrar Vaga"}</h3>
            <form onSubmit={(e) => e.preventDefault()}>
              <input
                type="text"
                name="titulo"
                value={formData.titulo}
                onChange={handleChange}
                placeholder="Título"
                className="mb-4 p-2 w-full border rounded"
              />
              <input
                type="text"
                name="descricao"
                value={formData.descricao}
                onChange={handleChange}
                placeholder="Descrição"
                className="mb-4 p-2 w-full border rounded"
              />
              <input
                type="text"
                name="nome_empresa"
                value={formData.nome_empresa}
                onChange={handleChange}
                placeholder="Nome da Empresa"
                className="mb-4 p-2 w-full border rounded"
              />
              <input
                type="date"
                name="data_abertura"
                value={formData.data_abertura}
                onChange={handleChange}
                placeholder="Data de Abertura"
                className="mb-4 p-2 w-full border rounded"
              />
              <input
                type="number"
                name="salario"
                value={formData.salario}
                onChange={handleChange}
                placeholder="Salário"
                className="mb-4 p-2 w-full border rounded"
              />
              <input
                type="text"
                name="empresa"
                value={formData.empresa}
                onChange={handleChange}
                placeholder="Empresa"
                className="mb-4 p-2 w-full border rounded"
              />
              <div className="flex justify-end">
                <button
                  type="button"
                  className="bg-gray-500 text-white py-2 px-4 rounded-lg mr-2"
                  onClick={() => setModalOpen(false)}
                >
                  Fechar
                </button>
                <button
                  type="button"
                  className="bg-green-500 text-white py-2 px-4 rounded-lg"
                  onClick={handleSubmit}
                >
                  {editingVaga ? "Atualizar" : "Cadastrar"}
                </button>
              </div>
            </form>
          </div>
        </div>
      )}
    </div>
  );
}
