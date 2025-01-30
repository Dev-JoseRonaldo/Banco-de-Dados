interface StudentCardProps {
  nome: string;
  idade: number;
  curso: string;
  anoMatricula: number;
  mediaGeral: number;
  endereco: string;
}

export default function StudentCard({
  nome,
  idade,
  curso,
  anoMatricula,
  mediaGeral,
  endereco,
}: StudentCardProps) {
  return (
    <div className="bg-white p-6 rounded-xl shadow-md w-80">
      <h2 className="text-2xl font-bold">{nome}</h2>
      <p className="text-gray-600">Idade: {idade}</p>
      <p className="text-gray-800">Curso: {curso}</p>
      <p className="text-gray-600">Ano de Matrícula: {anoMatricula}</p>
      <p className="font-semibold">Média Geral: {mediaGeral}</p>
      <p className="text-gray-600 mt-2">Endereço: {endereco}</p> {/* Exibindo o endereço */}
    </div>
  );
}
