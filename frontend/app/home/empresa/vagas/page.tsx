"use client";

import { useState } from "react";
import Header from "@/components/Header";

interface Vaga {
  id: number;
  titulo: string;
  cargo: string;
  descricao: string;
  salario: string;
  empresa: string;
  dataAbertura: string;
}

export default function VagasPage() {
  const [vagas, setVagas] = useState<Vaga[]>([
    { id: 1, titulo: "Desenvolvedor Jr.", cargo: "Dev Frontend", descricao: "Vaga para React", salario: "R$ 5.000", empresa: "Tech Corp", dataAbertura: "30/01/2025" },
    { id: 2, titulo: "Analista de Dados", cargo: "Data Analyst", descricao: "Vaga para análise de dados", salario: "R$ 6.000", empresa: "Data Inc", dataAbertura: "28/01/2025" },
    { id: 3, titulo: "Desenvolvedor Jr.", cargo: "Dev Frontend", descricao: "Vaga para React", salario: "R$ 5.000", empresa: "Tech Corp", dataAbertura: "30/01/2025" },
    { id: 4, titulo: "Analista de Dados", cargo: "Data Analyst", descricao: "Vaga para análise de dados", salario: "R$ 6.000", empresa: "Data Inc", dataAbertura: "28/01/2025" },
  ]);

  const [modalOpen, setModalOpen] = useState(false);
  const [editingVaga, setEditingVaga] = useState<Vaga | null>(null);
  const [formData, setFormData] = useState<Omit<Vaga, "id">>({
    titulo: "",
    cargo: "",
    descricao: "",
    salario: "",
    empresa: "",
    dataAbertura: "",
  });

  const handleDelete = (id: number) => {
    setVagas(vagas.filter(vaga => vaga.id !== id));
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
      cargo: "",
      descricao: "",
      salario: "",
      empresa: "",
      dataAbertura: "",
    });
    setModalOpen(true);
  };

  const handleSubmit = () => {
    if (editingVaga) {
      // Atualizar vaga
      setVagas(vagas.map(vaga => (vaga.id === editingVaga.id ? { ...vaga, ...formData } : vaga)));
    } else {
      // Cadastrar nova vaga
      const newVaga = { ...formData, id: Date.now() };
      setVagas([...vagas, newVaga]);
    }
    setModalOpen(false);
  };

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const { name, value } = e.target;
    setFormData(prev => ({ ...prev, [name]: value }));
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
          {vagas.map((vaga) => (
            <div key={vaga.id} className="bg-white p-4 rounded-lg shadow-md">
              <h3 className="text-xl font-bold">{vaga.titulo}</h3>
              <p className="text-gray-700">{vaga.cargo}</p>
              <p className="text-sm">{vaga.descricao}</p>
              <p className="text-green-600 font-bold">{vaga.salario}</p>
              <p className="text-gray-500 text-sm">Empresa: {vaga.empresa}</p>
              <p className="text-gray-400 text-xs">Aberta em: {vaga.dataAbertura}</p>

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
          ))}
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
                name="cargo"
                value={formData.cargo}
                onChange={handleChange}
                placeholder="Cargo"
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
              <input
                type="text"
                name="dataAbertura"
                value={formData.dataAbertura}
                onChange={handleChange}
                placeholder="Data de Abertura"
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
